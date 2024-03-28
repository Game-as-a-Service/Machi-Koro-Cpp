#ifndef CONTROLLERS_CLEAR_GAME_CONTROLLER_H
#define CONTROLLERS_CLEAR_GAME_CONTROLLER_H

#include <memory>
#include <string>

#include "drogon/HttpController.h"
#include "utils/util_base.h"
#include "utils/util.h"
#include "loggers/logger_base.h"
#include "loggers/logger.h"

using namespace drogon;

class ClearGame : public drogon::HttpController<ClearGame> {
public:
    METHOD_LIST_BEGIN
    METHOD_ADD(ClearGame::clearGame, "/{game_id}", Delete);
    METHOD_LIST_END

    void clearGame(const HttpRequestPtr& req,
                   std::function<void(const HttpResponsePtr&)>&& callback,
                   const std::string& game_id);

private:
    // Logger.
    std::shared_ptr<LoggerBase> log_ = Logger::self();

    // Utility.
    std::shared_ptr<UtilBase> util_ = Util::self();
};

#endif  // CONTROLLERS_CLEAR_GAME_CONTROLLER_H