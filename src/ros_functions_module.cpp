/*
* File: messages.cpp
* Author: m79lol, iskinmike
*
*/

#include <cstdarg>
#include <cstddef>
#include <string>

#include "module_headers/module.h"
#include "module_headers/function_module.h"

#include "ros_functions_module.h"
#include "sendCommandsLib.h"

// GLOBAL VARIABLES
int COUNT_ROS_FUNCTIONS = 22;
bool is_rosnode_not_started = true;


#define ADD_NODE_0_FUNCTION(FUNCTION_NAME) \
ros_functions[function_id] = new FunctionData(function_id + 1, 0, NULL, FUNCTION_NAME); \
function_id++;
//////

#define ADD_NODE_1S1F_FUNCTION(FUNCTION_NAME) \
Params = new FunctionData::ParamTypes[2]; \
Params[0] = FunctionData::STRING; \
Params[1] = FunctionData::FLOAT; \
ros_functions[function_id] = new FunctionData(function_id + 1, 2, Params, FUNCTION_NAME); \
function_id++;
//////

#define ADD_NODE_2S_FUNCTION(FUNCTION_NAME) \
Params = new FunctionData::ParamTypes[2]; \
Params[0] = FunctionData::STRING; \
Params[1] = FunctionData::STRING; \
ros_functions[function_id] = new FunctionData(function_id + 1, 2, Params, FUNCTION_NAME); \
function_id++;
//////

#define ADD_NODE_2S2F_FUNCTION(FUNCTION_NAME) \
Params = new FunctionData::ParamTypes[4]; \
Params[0] = FunctionData::STRING; \
Params[1] = FunctionData::STRING; \
Params[2] = FunctionData::FLOAT; \
Params[3] = FunctionData::FLOAT; \
ros_functions[function_id] = new FunctionData(function_id + 1, 4, Params, FUNCTION_NAME); \
function_id++;
//////

#define ADD_NODE_2S3F_FUNCTION(FUNCTION_NAME) \
Params = new FunctionData::ParamTypes[5]; \
Params[0] = FunctionData::STRING; \
Params[1] = FunctionData::STRING; \
Params[2] = FunctionData::FLOAT; \
Params[3] = FunctionData::FLOAT; \
Params[4] = FunctionData::FLOAT; \
ros_functions[function_id] = new FunctionData(function_id + 1, 5, Params, FUNCTION_NAME); \
function_id++;
//////

#define ADD_NODE_2S3F_FUNCTION(FUNCTION_NAME) \
Params = new FunctionData::ParamTypes[5]; \
Params[0] = FunctionData::STRING; \
Params[1] = FunctionData::STRING; \
Params[2] = FunctionData::FLOAT; \
Params[3] = FunctionData::FLOAT; \
Params[4] = FunctionData::FLOAT; \
ros_functions[function_id] = new FunctionData(function_id + 1, 5, Params, FUNCTION_NAME); \
function_id++;
//////

#define ADD_NODE_1S2F_FUNCTION(FUNCTION_NAME) \
Params = new FunctionData::ParamTypes[3]; \
Params[0] = FunctionData::STRING; \
Params[1] = FunctionData::FLOAT; \
Params[2] = FunctionData::FLOAT; \
ros_functions[function_id] = new FunctionData(function_id + 1, 3, Params, FUNCTION_NAME); \
function_id++;
//////

#define ADD_NODE_1S3F_FUNCTION(FUNCTION_NAME) \
Params = new FunctionData::ParamTypes[4]; \
Params[0] = FunctionData::STRING; \
Params[1] = FunctionData::FLOAT; \
Params[2] = FunctionData::FLOAT; \
Params[3] = FunctionData::FLOAT; \
ros_functions[function_id] = new FunctionData(function_id + 1, 4, Params, FUNCTION_NAME); \
function_id++;
//////

#define ADD_NODE_1S4F_FUNCTION(FUNCTION_NAME) \
Params = new FunctionData::ParamTypes[5]; \
Params[0] = FunctionData::STRING; \
Params[1] = FunctionData::FLOAT; \
Params[2] = FunctionData::FLOAT; \
Params[3] = FunctionData::FLOAT; \
Params[4] = FunctionData::FLOAT; \
ros_functions[function_id] = new FunctionData(function_id + 1, 5, Params, FUNCTION_NAME); \
function_id++;
//////

#define ADD_NODE_1S6F_FUNCTION(FUNCTION_NAME) \
Params = new FunctionData::ParamTypes[7]; \
Params[0] = FunctionData::STRING; \
Params[1] = FunctionData::FLOAT; \
Params[2] = FunctionData::FLOAT; \
Params[3] = FunctionData::FLOAT; \
Params[4] = FunctionData::FLOAT; \
Params[5] = FunctionData::FLOAT; \
Params[6] = FunctionData::FLOAT; \
ros_functions[function_id] = new FunctionData(function_id + 1, 7, Params, FUNCTION_NAME); \
function_id++;
//////

#define ADD_NODE_1S7F_FUNCTION(FUNCTION_NAME) \
Params = new FunctionData::ParamTypes[8]; \
Params[0] = FunctionData::STRING; \
Params[1] = FunctionData::FLOAT; \
Params[2] = FunctionData::FLOAT; \
Params[3] = FunctionData::FLOAT; \
Params[4] = FunctionData::FLOAT; \
Params[5] = FunctionData::FLOAT; \
Params[6] = FunctionData::FLOAT; \
Params[7] = FunctionData::FLOAT; \
ros_functions[function_id] = new FunctionData(function_id + 1,8, Params, FUNCTION_NAME); \
function_id++;
//////


#define DEFINE_ALL_FUNCTIONS \
ADD_NODE_2S3F_FUNCTION("sendHeader")\
ADD_NODE_2S2F_FUNCTION("sendMultiArrayDimension")\
ADD_NODE_1S1F_FUNCTION("sendBool")\
ADD_NODE_1S1F_FUNCTION("sendByte")\
ADD_NODE_1S1F_FUNCTION("sendChar")\
ADD_NODE_1S4F_FUNCTION("sendColorRGBA")\
ADD_NODE_1S1F_FUNCTION("sendFloat64")\
ADD_NODE_1S1F_FUNCTION("sendInt64")\
ADD_NODE_2S_FUNCTION("sendString")\
ADD_NODE_1S2F_FUNCTION("sendTime")\
ADD_NODE_1S1F_FUNCTION("sendUInt64")\
ADD_NODE_1S3F_FUNCTION("sendVector3")\
ADD_NODE_1S6F_FUNCTION("sendAccel")\
ADD_NODE_1S3F_FUNCTION("sendPoint")\
ADD_NODE_1S7F_FUNCTION("sendPose")\
ADD_NODE_1S3F_FUNCTION("sendPose2D")\
ADD_NODE_1S4F_FUNCTION("sendQuaternion")\
ADD_NODE_1S7F_FUNCTION("sendTransform")\
ADD_NODE_1S6F_FUNCTION("sendTwist")\
ADD_NODE_1S6F_FUNCTION("sendWrench")\
ADD_NODE_0_FUNCTION("initNode")\
ADD_NODE_0_FUNCTION("clearNode");


ROSFunctionModule::ROSFunctionModule() {
	ros_functions = new FunctionData*[COUNT_ROS_FUNCTIONS];
	system_value function_id = 0;

	FunctionData::ParamTypes *Params;
	function_id=0;

	DEFINE_ALL_FUNCTIONS
};

FunctionResult* ROSFunctionModule::executeFunction(system_value function_index, void **args) {
	if ((function_index < 1) || (function_index > COUNT_ROS_FUNCTIONS)) {
		return NULL;
	}
	if (is_rosnode_not_started){
		initNode();
		is_rosnode_not_started=false;
	}
	variable_value rez = 0;
	try {
		switch (function_index) {
		case 1: {
			std::string input1((const char *)args[0]);
			std::string input2((const char *)args[1]);
			variable_value *input3 = (variable_value *)args[2];
			variable_value *input4 = (variable_value *)args[3];
			variable_value *input5 = (variable_value *)args[4];
			sendHeader(input1, input2, *input3, *input4, *input5);
			break;
		}
		case 2: {
			std::string input1((const char *)args[0]);
			std::string input2((const char *)args[1]);
			variable_value *input3 = (variable_value *)args[2];
			variable_value *input4 = (variable_value *)args[3];
			sendMultiArrayDimension(input1, input2, *input3, *input4);
			break;
		}
		case 3: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			sendBool(input1, *input2);
			break;
		}
		case 4: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			sendByte(input1, *input2);
			break;
		}
		case 5: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			sendChar(input1, *input2);
			break;
		}
		case 6: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			variable_value *input3 = (variable_value *)args[2];
			variable_value *input4 = (variable_value *)args[3];
			variable_value *input5 = (variable_value *)args[4];
			sendColorRGBA(input1, *input2, *input3, *input4, *input5);
			break;
		}
		case 7: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			sendFloat64(input1, *input2);
			break;
		}
		case 8: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			sendInt64(input1, *input2);
			break;
		}
		case 9: {
			std::string input1((const char *)args[0]);
			std::string input2((const char *)args[1]);
			sendString(input1, input2);
			break;
		}
		case 10: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			variable_value *input3 = (variable_value *)args[2];
			sendTime(input1, *input2, *input3);
			break;
		}
		case 11: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			sendUInt64(input1, *input2);
			break;
		}
		case 12: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			variable_value *input3 = (variable_value *)args[2];
			variable_value *input4 = (variable_value *)args[3];
			sendVector3(input1, *input2, *input3, *input4);
			break;
		}
		case 13: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			variable_value *input3 = (variable_value *)args[2];
			variable_value *input4 = (variable_value *)args[3];
			variable_value *input5 = (variable_value *)args[4];
			variable_value *input6 = (variable_value *)args[5];
			variable_value *input7 = (variable_value *)args[6];
			sendAccel(input1, *input2, *input3, *input4, *input5, *input6, *input7);
			break;
		}
		case 14: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			variable_value *input3 = (variable_value *)args[2];
			variable_value *input4 = (variable_value *)args[3];
			sendPoint(input1, *input2, *input3, *input4);
			break;
		}
		case 15: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			variable_value *input3 = (variable_value *)args[2];
			variable_value *input4 = (variable_value *)args[3];
			variable_value *input5 = (variable_value *)args[4];
			variable_value *input6 = (variable_value *)args[5];
			variable_value *input7 = (variable_value *)args[6];
			variable_value *input8 = (variable_value *)args[7];
			sendPose(input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8);
			break;
		}
		case 16: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			variable_value *input3 = (variable_value *)args[2];
			variable_value *input4 = (variable_value *)args[3];
			sendPose2D(input1, *input2, *input3, *input4);
			break;
		}
		case 17: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			variable_value *input3 = (variable_value *)args[2];
			variable_value *input4 = (variable_value *)args[3];
			variable_value *input5 = (variable_value *)args[4];
			sendQuaternion(input1, *input2, *input3, *input4, *input5);
			break;
		}
		case 18: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			variable_value *input3 = (variable_value *)args[2];
			variable_value *input4 = (variable_value *)args[3];
			variable_value *input5 = (variable_value *)args[4];
			variable_value *input6 = (variable_value *)args[5];
			variable_value *input7 = (variable_value *)args[6];
			variable_value *input8 = (variable_value *)args[7];
			sendTransform(input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8);
			break;
		}
		case 19: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			variable_value *input3 = (variable_value *)args[2];
			variable_value *input4 = (variable_value *)args[3];
			variable_value *input5 = (variable_value *)args[4];
			variable_value *input6 = (variable_value *)args[5];
			variable_value *input7 = (variable_value *)args[6];
			sendTwist(input1, *input2, *input3, *input4, *input5, *input6, *input7);
			break;
		}
		case 20: {
			std::string input1((const char *)args[0]);
			variable_value *input2 = (variable_value *)args[1];
			variable_value *input3 = (variable_value *)args[2];
			variable_value *input4 = (variable_value *)args[3];
			variable_value *input5 = (variable_value *)args[4];
			variable_value *input6 = (variable_value *)args[5];
			variable_value *input7 = (variable_value *)args[6];
			sendWrench(input1, *input2, *input3, *input4, *input5, *input6, *input7);
			break;
		}
		case 21:{
			if (is_rosnode_not_started){
				initNode();
				is_rosnode_not_started=false;
			}
			break;
		}
		case 22:{
			if (!is_rosnode_not_started){
				clearNode();
				is_rosnode_not_started=true;
			}
			break;
		}

	};
		return new FunctionResult(1, rez);
	}
	catch (...){
		return new FunctionResult(0);
	};
};

void ROSFunctionModule::prepare(colorPrintf_t *colorPrintf_p, colorPrintfVA_t *colorPrintfVA_p) {
	colorPrintf = colorPrintf_p;
}
FunctionData** ROSFunctionModule::getFunctions(unsigned int *count_functions) {
	*count_functions = COUNT_ROS_FUNCTIONS;
	return ros_functions;
};
const char* ROSFunctionModule::getUID() {
	return "rosfunction_dll";
};
void *ROSFunctionModule::writePC(unsigned int *buffer_length) {
	*buffer_length = 0;
	return NULL;
}
int TestControlModule::startProgram(int uniq_index) {
	return 0;
}
void TestControlModule::readPC(void *buffer, unsigned int buffer_length) {
}
int ROSFunctionModule::endProgram(int uniq_index) {
	return 0;
}
void ROSFunctionModule::destroy() {
	for (unsigned int j = 0; j < COUNT_ROS_FUNCTIONS; ++j) {
		if (ros_functions[j]->count_params) {
			delete[] ros_functions[j]->params;
		}
		delete ros_functions[j];
	}
	delete[] ros_functions;
	delete this;
};

FunctionModule* getFunctionModuleObject() {
	return new ROSFunctionModule();
};