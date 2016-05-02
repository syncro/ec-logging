#ifndef LOG4CPPLOGGER_H
#define LOG4CPPLOGGER_H

#include <iostream>

//#include "logger.h"
#include "log4cpp/Category.hh"
#include "log4cpp/PropertyConfigurator.hh"
#include "loggerimpl.h"

class Log4cppLogger : public LoggerImpl
{
private:
    log4cpp::Category& rootLogger = log4cpp::Category::getRoot();

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
        rootLogger.debug("logger inited");
    }
    ~Log4cppLogger() {
        delete *rootLogger;
    }

	void info(std::string message) {
	    rootLogger.info(message);
	};
	void debug(std::string message) {
        rootLogger.debug(message);
	};
	void error(std::string message) {
        rootLogger.error(message);
	};
};



#endif // log4cpplogger.h


