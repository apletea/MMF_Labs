'use strict';

let Sequelize = require('sequelize');
let Model = require('../index');

let attributes = {
	id: {
		allowNull: false,
		autoIncrement: true,
		primaryKey: true,
		type: Sequelize.BIGINT
	},
	project_id : Sequelize.BIGINT,
	description : Sequelize.STRING,
	developer_id : Sequelize.BIGINT,
	status : Sequelize.INTEGER,
};

let options = {
	freezeTableName: true,
    timestamps: false,
    instanceMethods: {
    	getFullInfo: function(flags) {
    		let self = this;
    		return new Promise(resolve => {
    			self.getDeveloper().then(developer => {
    				if (developer) {
                        developer.getFullInfo().then(developerInfo => {
                            let ans = [];
                            ans.push(developerInfo);
                            ans.push(self.get());
                            if (flags) {
                                Model.Comment.findAll({where: {task_id: self.id}})
                                    .then(comments => {
                                        let promsies = comments.forEach(comment => {
                                            return comment.getFullInfo();
                                        });
                                        Promise.all(promsies).then(info => {
                                            ans.push(info);
                                            resolve({
                                            	task: self,
												comments: info
											});
                                        });
                                    });
                            }
                            else {
                                resolve(ans);
                            }
                        })
                    }
                    resolve(self);
    			})
    		});
    	}
    }
};

module.exports.attributes = attributes;
module.exports.options = options;