'use strict';

let getSuccesResponseJsonObject = data => {
	data = typeof data === 'undefined' ? null : data;
	return {
		status: 'succes',
		data: data
	}
};

let getErrorResponseJsonObject = (errorCode, message) => {
	let result = {
		status: 'error',
		error: errorCode
	};

	if (message)
		result.message = message;

	return result;
};

module.exports = {
	getErrorResponseJsonObject: getErrorResponseJsonObject,
	getSuccessResponseJsonObject: getSuccesResponseJsonObject
}