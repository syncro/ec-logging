#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>




class Logger
{
private:
    LoggerImpl* loggerImpl;
public:
    Logger() {
        loggerImpl = new Log4cppLogger();
    }
    ~Logger() {
        delete loggerImpl;
    }
	void info(std::string message) {
	    loggerImpl.info(message);
	};
	void debug(std::string message) {
        loggerImpl.debug(message);
	};
	void error(std::string message) {
        loggerImpl.error(message);
	};
};
};



#endif // Logger.h


