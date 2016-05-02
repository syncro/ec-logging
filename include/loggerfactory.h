#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H

#include <iostream>

#include "log4cpplogger.h"
#include "logger.h"

typedef Logger<Log4cppLogger> ConcreteLogger;

class LoggerFactory
{
private:

public:
	virtual ~LoggerFactory();
	static LoggerImpl* getLogger(std::string ident) {
	    LoggerImpl* logger = new ConcreteLogger();
        return logger;
	}
};



#endif // LoggerFactory.h


