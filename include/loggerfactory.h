#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H

#include <iostream>

#include "log4cpplogger.h"
#include "logger.h"

class LoggerFactory
{
private:

public:
	virtual ~LoggerFactory();
	static Logger* getLogger(std::string indent) {
	    Logger<Log4cppLogger> LoggerImpl;
	    Logger* logger = new LoggerImpl();
        return logger;
	}
};



#endif // LoggerFactory.h


