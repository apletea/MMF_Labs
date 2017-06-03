'use strict';

let Sequelize = require('sequelize');

let attributes = {
	id: {
		allowNull: false,
		autoIncrement: true,
		primaryKey: true,
		type: Sequelize.BIGINT
	},
	task_id: Sequelize.BIGINT,
	user_id: Sequelize.BIGINT,
	time: {
		type:Sequelize.BIGINT,
		defaultValue : Math.floor(Date.now() / 1000)
	},
	comment : Sequelize.STRING
};

let options = {
	freezeTableName: true,
    timestamps: false,
    instanceMethods: {
    	getFullInfo: function() {
    		let self = this;
    		return new Promise(resolve => {
    			self.getUser().then(user => {
    				user.getFullInfo().then(userInfo => {
    					let ans = [];
    					ans.push(userInfo);
    					ans.push(self.get());
    					resolve(ans);
    				})
    			})
    		});
    	}
    }
};

module.exports.attributes = attributes;
module.exports.options = options;