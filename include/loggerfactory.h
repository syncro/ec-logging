#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H

#include <iostream>

#include "log4cpplogger.h"


class LoggerFactory
{
private:

public:
	virtual ~LoggerFactory();
	static Logger* getLogger(std::string indent) {
	    Logger* logger = new Logger();
        return logger;
	}
};



#endif // LoggerFactory.h


