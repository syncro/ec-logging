#ifndef LOG4CPPLOGGER_H
#define LOG4CPPLOGGER_H

#include <iostream>

#include "logger.h"


class Log4cppLogger : public Logger
{
private:
    log4cpp::Category* loggerImpl;

public:
    Log4cppLogger() {
        const char *file_log4cpp_init = "log4cpp.properties";
        try
        {
            log4cpp::PropertyConfigurator::configure(file_log4cpp_init);
        }
        catch (log4cpp::ConfigureFailure &e)
        {
            std::cout
                << e.what()
                << " [log4cpp::ConfigureFailure catched] while reading "
                << file_log4cpp_init
                << std::endl;

            exit(1);
        }
        loggerImpl = log4cpp::Category::getRoot();
        loggerImpl.debug("logger inited");
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



#endif // Logger.h


