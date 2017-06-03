let express = require('express');

module.exports = (app, passport) => {

	app.all('/*', function(req, res, next) {
        res.header("Access-Control-Allow-Origin", "*");
        res.header("Access-Control-Allow-Headers", "X-Requested-With, Content-Type, Authorization");
        res.header("Access-Control-Allow-Methods", "GET, POST","PUT");
        next();
    });

	let userRouter = require('./user')(express, passport);
	let projectRouter = require('./project')(express, passport);
	let taskRouter = require('./task')(express,passport);
	let commentRouter = require('./comment')(express,passport);	

	app.use ('/api/user', userRouter);
	app.use ('/api/project', projectRouter);
	app.use ('/api/task',taskRouter);
	app.use ('/api/comment', commentRouter);
};