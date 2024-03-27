#include "loggers/logger.h"

#include "trantor/utils/Logger.h"

std::shared_ptr<Logger> Logger::self()
{
    static std::shared_ptr<Logger> log(new Logger);
    return log;
}

void Logger::trace(const std::string& msg) const
{
    LOG_TRACE << msg;
}

void Logger::debug(const std::string& msg) const
{
    LOG_DEBUG << msg;
}

void Logger::info(const std::string& msg) const
{
    LOG_INFO << msg;
}

void Logger::warn(const std::string& msg) const
{
    LOG_WARN << msg;
}

void Logger::error(const std::string& msg) const
{
    LOG_ERROR << msg;
}

void Logger::fatal(const std::string& msg) const
{
    LOG_FATAL << msg;
}