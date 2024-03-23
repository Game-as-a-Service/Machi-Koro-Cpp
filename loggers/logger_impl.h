#ifndef LOGGERS_LOGGER_IMPL_H
#define LOGGERS_LOGGER_IMPL_H

#include <memory>
#include <string>

#include "loggers/logger.h"

class LoggerImpl : public Logger {
public:
    LoggerImpl(const LoggerImpl&) = delete;

    LoggerImpl& operator=(const LoggerImpl&) = delete;

    static std::shared_ptr<LoggerImpl> self();

    void trace(const std::string& msg) const override;

    void debug(const std::string& msg) const override;

    void info(const std::string& msg) const override;

    void warn(const std::string& msg) const override;

    void error(const std::string& msg) const override;

    void fatal(const std::string& msg) const override;

private:
    LoggerImpl() = default;
};

#endif  // LOGGERS_LOGGER_IMPL_H