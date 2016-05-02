#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

template<typename T>
class Logger
{
private:
    T* loggerImpl;
public:
    Logger() {
        loggerImpl = new T();
    }
    ~Logger() {
        delete loggerImpl;
    }
	void info(std::string message) {
	    loggerImpl->info(message);
	};
	void debug(std::string message) {
        loggerImpl->debug(message);
	};
	void error(std::string message) {
        loggerImpl->error(message);
	};

};



#endif // Logger.h


