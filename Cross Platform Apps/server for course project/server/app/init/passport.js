'use strict';

let Model = require('../model'),
	JwtStrategy = require('passport-jwt').Strategy,
	ExtractJwt = require('passport-jwt').ExtractJwt,
	secretOrKey = require('../config').secretOrKey;

module.exports = passport => {

	let options = {
		secretOrKey: secretOrKey,
		jwtFromRequest: ExtractJwt.fromAuthHeader()
	};
	console.log(options.jwtFromRequest);
	passport.use(new JwtStrategy(options, (jwt_payload, done) => {
			let query = {};
			if (jwt_payload.email){
				query.email = jwt_payload.email;
			}

			Model.User.findOne({where:query})
				.then( user => {
					if (!user){
						done(null,false);
						return;
					}

					done(null, user);
				})
		}
	));
}