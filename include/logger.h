#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>




class Logger
{
private:

public:
	virtual void info(std::string message);
	virtual void debug(std::string message);
	virtual void error(std::string message);
    Logger() {};
    virtual ~Logger();
};



#endif // Logger.h


