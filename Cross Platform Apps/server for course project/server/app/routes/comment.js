'use strict';

let Model  = require('../model'),
    errorUtil = require('../utils/errors').errorCodes,
    responseUtil = require('../utils/response'),
    authHelper = require('../utils/auth');

const userConst = require('../constants/userConstants');

module.exports = (express, passport) => {
	let router = express.Router();

	router.post('/updatecomment', authHelper.allowForUsers(passport), (req,res) => {
		let commentID = req.query.id;
		Model.Comment.findOne( {where : {id:commentID}})
			.then(comment => {
				comment.update({comment: req.body.comment}).then(newComment => {
                    newComment.getFullInfo().then(info => {
                        return res.json(responseUtil.getSuccessResponseJsonObject(info));
                    })
                })
			}).catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN, err));
			})
	});

	router.get('/deletecomment', authHelper.allowForUsers(passport), (req,res) => {
		let commentID = req.query.id;
		Model.Comment.destroy({where : {id : commentID}})
			.then(info => {
				return	res.json(responseUtil.getSuccessResponseJsonObject(info));
			}).catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN,err));
			})
	});

	router.post('/addcomment', authHelper.allowForUsers(passport), (req,res) => {
		let taskID = req.query.id;
		let comment ={
			task_id : taskID,
			user_id : req.user.get().id,
			comment : req.body.comment
		};
		Model.Comment.create(comment)
			.then(comment => {
				comment.getFullInfo().then(info => {
					return res.json(responseUtil.getSuccessResponseJsonObjecte(info));
				})
			}).catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN,err));
			})
	});



	return router;
};

