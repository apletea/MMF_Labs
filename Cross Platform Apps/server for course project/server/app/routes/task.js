'use strict';

let Model  = require('../model'),
    errorUtil = require('../utils/errors'),
    responseUtil = require('../utils/response'),
    authHelper = require('../utils/auth');

const userConst = require('../constants/userConstants');

module.exports = (express, passport) => {
	let router = express.Router();


	router.get('/mytasks', authHelper.allowForDevelopers(passport), (req,res) => {
		Model.Task.findAll({where : {developer_id: req.user.get().id}})
			.then(tasks => {
				let promises = tasks.map(task => {
					return task.getFullInfo();
				});
				Promise.all(promises).then(info => {
					return res.json(responseUtil.getSuccessResponseJsonObject(info));
				});
			}).catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN, err));
			})
	});


	router.get('/givetask', authHelper.allowForManagers(passport), (req,res) => {
		let taskID = req.query.task_id;
		let developerID = req.query.dev_id;
		Model.Task.findOne({where:{id: taskID}})
			.then(task => {
				task.update({developer_id: developerID}).then(task => {
					task.getFullInfo().then(info => {
						return res.json(responseUtil.getSuccessResponseJsonObject(info));
					})
                })
			}).catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN, err));
			})
	});

	router.get('/updatetask', authHelper.allowForUsers(passport), (req,res) => {
		let taskID = req.query.id;	
		let newStatus = req.query.status;
		Model.Task.findOne({where: {id : taskID}})
			.then(task => {
				task.update({status: newStatus}).then(updatedTask => {
					updatedTask.getFullInfo().then(info => {
						return res.json(responseUtil.getSuccessResponseJsonObject(info));
					})
                })
			}).catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN,err));
			})
	});

	router.get('/gettask', authHelper.allowForUsers(passport), (req,res) => {
		let taskID = req.query.id;
		Model.Task.findOne({where : {id : taskID}})
			.then(task => {
				task.getFullInfo({withComments : true})
					.then(info => {
						return res.json(responseUtil.getSuccessResponseJsonObject(info));
					})
			}).catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN,err));
			})
	});

	router.post('/createtask', authHelper.allowForUsers(passport), (req,res) => {
		let projectID = req.query.id;
		let task = {
			project_id: projectID,
			description : req.body.description,
			status : 1
		};
		Model.Task.create(task)
			.then(newTask => {
				newTask.getFullInfo().then(info => {
					return res.json(responseUtil.getSuccessResponseJsonObject(info));
				})
			}).catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN,err));
			})
	});

	return router;
};

