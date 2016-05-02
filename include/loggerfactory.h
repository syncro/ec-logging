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
	static ConcreteLogger* getLogger(std::string ident) {
	    ConcreteLogger* logger = new ConcreteLogger();
        return logger;
	}
};



#endif // LoggerFactory.h


