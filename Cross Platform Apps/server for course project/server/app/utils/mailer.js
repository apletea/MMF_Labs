'use strict';

let nodemailer = require('nodemailer');

let config = {
	email:{
		service: 'gmail',
		auth: {
			user: 'regstration.confimr@gmail.com',
			pass: 'zxcvbnm,.'
		}
	}
};

let transoprter = nodemailer.createTransport(config.email);

module.exports = (data, emails) => {

	let mailOptions = {
		from: 'Service LOG <${config.email.auth.user}>',
		to: emails,
		subject: 'Service Confirm Registration',
		text: data
	};

	transoprter.sendMail(mailOptions, (err, info) => {
		console.log(info);
	});

};