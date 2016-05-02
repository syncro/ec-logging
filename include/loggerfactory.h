#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H

#include <iostream>
#include "logger.h"
#include "log4cpplogger.h"
typedef Logger<Log4cppLogger> ConcreteLogger;




class LoggerFactory
{
private:

public:
	virtual ~LoggerFactory();
	static ConcreteLogger* getLogger(std::string ident) {
	    ConcreteLogger* logger = new ConcreteLogger();
        return logger;
	}
};



#endif // LoggerFactory.h


