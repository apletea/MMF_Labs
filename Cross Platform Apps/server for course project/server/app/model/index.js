'use strict';

let UserMeta = require('./User'),
    ProjectMeta = require('./Project'),
    CommentMeta = require('./Comment'),
    TaskMeta = require('./Task');

let connection = require('../init/sequalize');

let User = connection.define('users', UserMeta.attributes, UserMeta.options);
let Project = connection.define('project', ProjectMeta.attributes, ProjectMeta.options);
let Task = connection.define('task', TaskMeta.attributes, TaskMeta.options);
let Comment = connection.define('comments', CommentMeta.attributes, CommentMeta.options);

Project.belongsTo(User,{foreignKey: 'creator', as: 'Manager'});
Task.belongsTo(Project, {foreignKey: 'project_id', as: 'Project'});
Task.belongsTo(User, {foreignKey: 'developer_id', as: 'Developer'});
Comment.belongsTo(Task, {foreignKey: 'task_id', as: 'Task'});
Comment.belongsTo(User, {foreignKey: 'user_id',as: 'User'});


module.exports = {
	User : User,
	Project: Project,
	Task : Task,
	Comment : Comment
};

