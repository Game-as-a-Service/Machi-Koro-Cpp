#ifndef LOGGERS_LOGGER_BASE_H
#define LOGGERS_LOGGER_BASE_H

#include <string>

class LoggerBase {
public:
    virtual ~LoggerBase() = default;

    virtual void trace(const std::string& msg) const = 0;

    virtual void debug(const std::string& msg) const = 0;

    virtual void info(const std::string& msg) const = 0;

    virtual void warn(const std::string& msg) const = 0;

    virtual void error(const std::string& msg) const = 0;

    virtual void fatal(const std::string& msg) const = 0;
};

#endif  // LOGGERS_LOGGER_BASE_H