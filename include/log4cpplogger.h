#ifndef LOGGER
#define LOGGER

#include <iostream>

#include "logger.h"


class Log4cppLogger : public Logger
{
private:
    log4cpp::Category &logerImpl;

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
        log4cpp::Category &logerImpl = log4cpp::Category::getRoot();
        logerImpl.debug("logger inited");
    }
	void info(std::string message) {
	    logerImpl.info(message);
	};
	void debug(std::string message) {
        logerImpl.debug(message);
	};
	void error(std::string message) {
        logerImpl.error(message);
	};
};



#endif // Logger.h


