'use strict';

let Sequelize = require('sequelize');
let hooks = require('./hooks');

let attributes = {
	id: {
		allowNull: false,
		autoIncrement: true,
		primaryKey: true,
		type: Sequelize.BIGINT
	},
	email: {
		type: Sequelize.STRING,
		unique: true,
		validate: {
			isEmail: true
		}
	},
	password: Sequelize.STRING,
	is_confirm: {
		type: Sequelize.BOOLEAN,
		defaultValue: false
	},
	role: Sequelize.INTEGER,
	first_name: Sequelize.STRING,
	second_name : Sequelize.STRING,
	token: Sequelize.STRING
};

let options = {
	hooks: hooks,
	freezeTableName: true,
    timestamps: false,
    instanceMethods: {
    	getFullInfo: function() {
    		let self = this;
    		return new Promise(resolve => {
    			resolve({
    				id : self.id,
    				email : self.email,
    				role : self.role,
    				first_name : self.first_name,
    				second_name : self.second_name
    			})
    		});
    	}
    }
};

module.exports.attributes = attributes;
module.exports.options = options;