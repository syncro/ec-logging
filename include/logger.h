#ifndef LOGGER
#define LOGGER

#include <iostream>




class Logger
{
private:

public:
	virtual info(std::string message);
	virtual debug(std::string message);
	virtual error(std::string message);
    virtual ~Logger();
};



#endif // Logger.h


