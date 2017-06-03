'use strict';

let Model  = require('../model'),
    errorUtil = require('../utils/errors').errorCodes,
    responseUtil = require('../utils/response'),
    authHelper = require('../utils/auth');

const userConst = require('../constants/userConstants');

module.exports = (express, passport) => {
	let router = express.Router();

	router.get('/myprojectsd', authHelper.allowForDevelopers(passport), (req,res) => {
		let userID = req.user.id;
        Model.Project.findAll().then(projects => {
			let ans = [];
                let promises = projects.map(project => {
					let dev = project.developers;
					let tmp = dev.map(devloper => {
						if (+devloper === +userID){
							ans.push(project);
						}
						else{
							return;
						}
					});
					Promise.all(tmp).then(() => {
						return;
					})
				});
				Promise.all(promises).then(() => {
					return res.json(responseUtil.getSuccessResponseJsonObject(ans));
				});
			}).catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN, err));
			})
	});

	router.get('/myprojectsm', authHelper.allowForManagers(passport), (req,res) => {
		let managerID = req.user.get().id;
		Model.Project.findAll({where : {creator : managerID }})
			.then(projects => {
				let promises = projects.map(project => {
					return project.getFullInfo();
				});
				Promise.all(promises)
					.then(info => {
						return res.json(responseUtil.getSuccessResponseJsonObject(info));
					});
			})
			.catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN, err));
			})
	});

	router.get('/myprojects', authHelper.allowForUsers(passport), (req,res) => {
		if (+req.user.get().role === userConst.USER_ROLE_MANAGER){
            let managerID = req.user.get().id;
            Model.Project.findAll({where : {creator : managerID }})
                .then(projects => {
                    let promises = projects.map(project => {
                        return project.getFullInfo();
                    });
                    Promise.all(promises)
                        .then(info => {
                            return res.json(responseUtil.getSuccessResponseJsonObject(info));
                        });
                })
                .catch(err => {
                    return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN, err));
                })
		}
		else{
            let userID = req.user.id;
            Model.Project.findAll().then(projects => {
                let ans = [];
                let promises = projects.map(project => {
                    let dev = project.developers;
                    let tmp = dev.map(devloper => {
                        if (+devloper === +userID){
                            ans.push(project);
                        }
                        else{
                            return;
                        }
                    });
                    Promise.all(tmp).then(() => {
                        return;
                    })
                });
                Promise.all(promises).then(() => {
                    return res.json(responseUtil.getSuccessResponseJsonObject(ans));
                });
            }).catch(err => {
                return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN, err));
            })
		}
	});

	router.post('/createproject', authHelper.allowForManagers(passport), (req,res) => {
		let newProject = {
			name: req.body.name,
			creator : req.user.get().id
		};
		Model.Project.create(newProject)
			.then(project => {
				project.getFullInfo()
					.then(info => {
						return res.json(responseUtil.getSuccessResponseJsonObject(info));
					})
			})
			.catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN,err));
			})
	});

	router.get('/addtoproject', authHelper.allowForManagers(passport), (req,res) => {
		let developerID = req.query.dev_id;
		let projectID = req.query.project_id;
		Model.Project.findOne({where: {id : projectID}})
			.then(project => {
				let developers = project.developers;
				if (!developers)
					developers = [developerID];
				else
					developers.push(developerID);
				project.update({developers: developers})
					.then(project => {
						project.getFullInfo().then(info => {
							return res.json(responseUtil.getSuccessResponseJsonObject(info));
						})
					})
			}).catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN,err));
			})
	});

	router.get('/gettasks', authHelper.allowForUsers(passport), (req,res) => {
		let projectID = req.query.id;
		Model.Task.findAll({where : {project_id : projectID}})
			.then(tasks => {
				let promises = tasks.map(task => {
					return task.getFullInfo();
				});
				Promise.all(promises).then(info => {
					return res.json(responseUtil.getSuccessResponseJsonObject(info));
				})
			}).catch(err => {
				return res.json(responseUtil.getErrorResponseJsonObject(errorUtil.ERR_UNKNOWN, err));
			})
	});



	return router;
};

