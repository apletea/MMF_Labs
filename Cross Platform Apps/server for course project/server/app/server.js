'use strict';

let express = require('express'),
	bodyParser = require('body-parser'),
	passport = require('passport'),
	setUpPassport = require('./init/passport'),
	setUpRoutes = require('./routes'),
	app = express();

app.use(bodyParser.urlencoded({
	extended: true
}));

app.use(bodyParser.json());

app.use(passport.initialize());

setUpPassport(passport);
setUpRoutes(app,passport);

app.listen(8080, () => {
	console.log('App on 8080');
});