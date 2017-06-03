'use strict';

let bcrypt = require('bcrypt'),
	jwt = require('jwt-simple'),
	request = require('request'),
	md5 = require('md5'),
	secretOrKey = require('../config').secretOrKey;

const compose = require('composable-middleware');
const errorUtil = require('./errors');
const responseUtil = require('./response');
const userConst = require('../constants/userConstants');

let comparePassword = (password, hash, cb) => {
	bcrypt.compare(password, hash.replace(), (err, isMatch) => {
		if (err)
			return cb(err);
		cb(null, isMatch);
	});
};

let hashPassword = (pass, cb) => {
	bcrypt.genSalt(10, (err, salt) => {

		if (err)
			return cb(err);

		bcrypt.hash(pass, salt, (err, hash) => {
			if (err)
				return cb(err);

			cb(null, hash);
		});
	});
};

let getJwtToken = user => {
	return `JWT ${jwt.encode(user, secretOrKey)}`;
};
	
let allowForUsers = (passport) => {
	return passport.authenticate('jwt', {session : false});
};

let allowForDevelopers = (passport) => {
	return compose()
		.use(allowForUsers(passport))
		.use(function (req, res, next){
			const user = req.user;
			if (user.role ===  userConst.USER_ROLE_DEVELOPER){
				next();
			}
			else{
				res.status(403).json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_OBJECT_ACCESS, 'Action allowe only for developers'));
			}
		});
};

let allowForManagers = (passport) => {
	return compose()
		.use(allowForUsers(passport))
		.use(function (req, res, next){
			const user = req.user;
			if (user.role ===  userConst.USER_ROLE_MANAGER){
				next();
			}
			else{
				res.status(403).json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_OBJECT_ACCESS, 'Action allowe only for managers'));
			}
		});
}


module.exports = {
	comparePassword: comparePassword,
    hashPassword: hashPassword,
    getJwtToken: getJwtToken,
    allowForDevelopers : allowForDevelopers,
    allowForManagers : allowForManagers,
    allowForUsers : allowForUsers
};
