#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H

#include <iostream>

#include "log4cpplogger.h"
#include "logger.h"

Logger<Log4cppLogger> LoggerImpl;

class LoggerFactory
{
private:

public:
	virtual ~LoggerFactory();
	static LoggerImpl* getLogger(std::string indent) {
	    LoggerImpl* logger = new LoggerImpl();
        return logger;
	}
};



#endif // LoggerFactory.h


