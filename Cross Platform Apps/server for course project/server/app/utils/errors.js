'use strict';

let responseUtil = require('./response');

const errorCodes = {
	'ERR_UNKNOWN': 0,
    'ERR_USER_LOGIN_FAIL': 1101,
    'ERR_USER_REGISTER_EMAIL_INUSE': 1201,
    'ERR_USER_REGISTER_EMAIL_INVALID': 1202,
    'ERR_USER_REGISTER_PASSWORD_INVALID': 1203,
    'ERR_ARGUMENT_MISSED': 10005,
    'ERR_ARGUMENT_INVALID': 10006,
    'ERR_OBJECT_NOT_FOUND': 10011,
    'ERR_OBJECT_ACCESS': 1002,
    'ERR_OBJECT_INVALID': 10013,
    'ERR_OBJECT_EXIST': 10014,
    'ERR_METHOD_DEPRECATED': 10015,
    'ERR_METHOD_NOT_ALLOWED_FOR_GUESTS': 10016,
};

const errorCodesIntegers = Object.keys(errorCodes).map(key => {
	return errorCodes[key];
});

let checkRequiredParams = (req, params, errorCode) => {
	params.forEach(param => {
		if (!req.param)
			return responseUtil.getErrorResponseJsonObject(errorCode, 'Missing {$param}');
	});
};

module.exports = {
	errorCodes: errorCodes,
	checkRequiredParams: checkRequiredParams,

	catchErr: res => {
		return err =>  {
		    const errorStatus = 'status' in err && err.status >= 200 && err.status <= 599 ? +err.status : 400;
            const errorCode = 'code' in err && errorCodesIntegers.indexOf(+err.code) !== -1 ? +err.code : errorCodes.ERR_UNKNOWN;
            const errorMessage = 'message' in err ? err.message.toString().trim() : '';

            res.status(errorStatus).json(responseUtil.getErrorResponseJsonObject(errorCode, errorMessage));
		};
	}
};

