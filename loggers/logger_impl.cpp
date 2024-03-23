#include "loggers/logger_impl.h"

#include "trantor/utils/Logger.h"

std::shared_ptr<LoggerImpl> LoggerImpl::self()
{
    static std::shared_ptr<LoggerImpl> log(new LoggerImpl);
    return log;
}

void LoggerImpl::trace(const std::string& msg) const
{
    LOG_TRACE << msg;
}

void LoggerImpl::debug(const std::string& msg) const
{
    LOG_DEBUG << msg;
}

void LoggerImpl::info(const std::string& msg) const
{
    LOG_INFO << msg;
}

void LoggerImpl::warn(const std::string& msg) const
{
    LOG_WARN << msg;
}

void LoggerImpl::error(const std::string& msg) const
{
    LOG_ERROR << msg;
}

void LoggerImpl::fatal(const std::string& msg) const
{
    LOG_FATAL << msg;
}