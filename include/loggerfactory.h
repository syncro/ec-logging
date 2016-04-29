#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H

#include <iostream>




class LoggerFactory
{
private:

public:
	virtual ~LoggerFactory();
	Logger* getLogger(std::string indent) {
	    Logger* logger = new Log4cppLogger();
        return logger;
	}
};



#endif // LoggerFactory.h


