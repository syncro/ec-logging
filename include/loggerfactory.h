#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H

#include <iostream>

#include "log4cpplogger.h"


class LoggerFactory
{
private:

public:
	virtual ~LoggerFactory();
	static Log4cppLogger* getLogger(std::string indent) {
	    Log4cppLogger* logger = new Log4cppLogger();
        return logger;
	}
};



#endif // LoggerFactory.h


