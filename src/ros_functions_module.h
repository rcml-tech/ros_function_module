/*
* File: ros_function_module.h
* Author: m79lol, iskinmike
*
*/

#ifndef ROS_FUNCTION_MODULE_H
#define	ROS_FUNCTION_MODULE_H

class ROSFunctionModule : public FunctionModule {
	FunctionData **ros_functions;

public:

	colorPrintfModule_t *colorPrintf;
	ROSFunctionModule();

	//init
	const char *getUID();
	void prepare(colorPrintfModule_t *colorPrintf_p, colorPrintfModuleVA_t *colorPrintfVA_p);

	//compiler only
	FunctionData **getFunctions(unsigned int *count_functions);
	void *writePC(unsigned int *buffer_length);

	//intepreter - program & lib
	void readPC(void *buffer, unsigned int buffer_length);

	//intepreter - program
	FunctionResult* executeFunction(system_value function_index, void **args);
	int startProgram(int uniq_index);
	int endProgram(int uniq_index);

	//destructor
	void destroy();
	~ROSFunctionModule() {};
};

#endif	/* ros_FUNCTION_MODULE_H  */