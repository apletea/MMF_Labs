'use strict';

let Model = require('../model');
let emailNotification = require('../utils/mailer');
let errorUtil = require('../utils/errors');
let responseUtil = require('../utils/response');
let authHelper = require('../utils/auth');
let userConst = require('../constants/userConstants');

module.exports = (express, passport) => {
	let router = express.Router();

	router.get('/getMe', passport.authenticate('jwt',{session: false}), (req,res) => {
		let user = req.user;
		return res.json(responseUtil.getSuccessResponseJsonObject(user));
	});

	router.post('/register', (req,res) => {
		console.log(req.body);
		Model.User.findOne({
			where: {
				email: req.body.email.trim().toLowerCase()
			}
		})
			.then(user => {
				if (user) {
					return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_OBJECT_ACCESS,'User with such email already exsist'));
				}

				Model.User.create(req.body)
					.then(newUser => {
						emailNotification("Please confirm your registration by the following this link: localhost:8080/api/user/confirm?id="+newUser.id, newUser.email);
						return res.json(responseUtil.getSuccessResponseJsonObject('Confirm your email'));
					})
			})
			.catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN,err));
			})
	});

	router.get('/confirm', (req,res) => {
		let userID = req.query.id;
		Model.User.findOne({
			where: {
				id: userID
			}
		})
			.then(user => {
				user.update({is_confirm: true})
					.then(() => {
						return res.json(responseUtil.getSuccessResponseJsonObject('Email confirmed'));
					})
			})
			.catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN, err));
			})
	});

	router.get('/login', (req,res) => {
		let email = req.query.email;
		let password = req.query.password;

		let errorObject = errorUtil.checkRequiredParams(req,['email','password'], errorUtil.errorCodes.ERR_USER_LOGIN_FAIL);

		if (errorObject) {
			return res.json(errorObject);
		}

		Model.User.findOne({where: {
			email: email.trim().toLowerCase(),
			is_confirm: true
		}})
		.then(result => {
			if (!result){
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.errorCodes.ERR_USER_LOGIN_FAIL,'Invalid login or password'));
			}

			let user = result.get();

			authHelper.comparePassword(password, user.password, (err, isMatch) => {
				if (isMatch && !err){
					result.getFullInfo()
						.then(content => {
							content.token = result.token;
							return res.json(responseUtil.getSuccessResponseJsonObject(content));
						})
				}
				else {
					res.status(403);
					return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.errorCodes.ERR_USER_LOGIN_FAIL, 'Invalid login or Password'));			}
			})
		})
	});


	

	router.get('/searchdeveloper', authHelper.allowForManagers(passport), (req,res) => {
		let query = {role: userConst.USER_ROLE_DEVELOPER};
		if (req.query.first_name){
			query.first_name = req.query.first_name;
		}
		if (req.query.second_name){
			query.second_name = req.query.second_name;
		}
		Model.User.findAll({where: query})
			.then( users => {
				let promises = users.map(user => {
					return user.getFullInfo();
				});
				Promise.all(promises)
					.then(info => {
						return res.json(responseUtil.getSuccessResponseJsonObject(info));
					})
			})
			.catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN, err));
			})
	});


	return router;
};