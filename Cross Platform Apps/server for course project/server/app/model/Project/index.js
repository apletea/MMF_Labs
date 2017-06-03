'use strict';

let Sequelize = require('sequelize');

let attributes = {
	id: {
		allowNull: false,
		autoIncrement: true,
		primaryKey: true,
		type: Sequelize.BIGINT
	},
	name: Sequelize.STRING,
	creator: Sequelize.BIGINT,
	developers : Sequelize.ARRAY(Sequelize.BIGINT)
};

let options = {
	freezeTableName: true,
    timestamps: false,
    instanceMethods: {
    	getFullInfo: function() {
    		let self = this;
    		return new Promise(resolve => {
    			self.getManager().then(manager => {
    				manager.getFullInfo().then(managerInfo => {
    					let ans = [];
    					ans.push(managerInfo);
    					ans.push(self.get());
    					resolve({
    						manager : managerInfo,
							project : self.get()
						});
    				});
    			});
    		});
    	}
    }
};

module.exports.attributes = attributes;
module.exports.options = options;