'use strict';

let authHelper = require ('../../utils/auth');

let beforeCreate = (user, options) => {
	return new Promise ((resolve, reject) => {

		if (user.email)
			user.email = user.email.trim().toLowerCase();
		if (user.password)
			user.password = user.password.toString();

		user.token = authHelper.getJwtToken({email: user.email, password: user.password});

		if (!user.password)
			resolve();
		authHelper.hashPassword(user.password, (err, hashedPassword) =>{
			if (err)
				reject(err);
			user.password = hashedPassword;
			resolve();
		});
	});
};

module.exports = {
	beforeCreate: beforeCreate 
}