#ifndef LOGGERIMPL_H
#define LOGGERIMPL_H

#include <iostream>


class LoggerImpl
{
	virtual void info(std::string message) const = 0;
	virtual void debug(std::string message) const = 0;
	virtual void error(std::string message) const = 0;
};



#endif // loggerimpl.h


