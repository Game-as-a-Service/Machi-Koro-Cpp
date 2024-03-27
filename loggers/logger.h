#ifndef LOGGERS_LOGGER_H
#define LOGGERS_LOGGER_H

#include <memory>
#include <string>

#include "loggers/logger_base.h"

class Logger : public LoggerBase {
public:
    Logger(const Logger&) = delete;

    Logger& operator=(const Logger&) = delete;

    static std::shared_ptr<Logger> self();

    void trace(const std::string& msg) const override;

    void debug(const std::string& msg) const override;

    void info(const std::string& msg) const override;

    void warn(const std::string& msg) const override;

    void error(const std::string& msg) const override;

    void fatal(const std::string& msg) const override;

private:
    Logger() = default;
};

#endif  // LOGGERS_LOGGER_H