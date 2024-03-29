#ifndef CONTROLLERS_INIT_GAME_CONTROLLER_H
#define CONTROLLERS_INIT_GAME_CONTROLLER_H

#include <memory>

#include "drogon/HttpController.h"
#include "utils/util_base.h"
#include "utils/util.h"
#include "loggers/logger_base.h"
#include "loggers/logger.h"

using namespace drogon;

class InitGame : public drogon::HttpController<InitGame> {
public:
    METHOD_LIST_BEGIN
    METHOD_ADD(InitGame::initGame, "/{game_id}", Post);
    METHOD_LIST_END

    void initGame(const HttpRequestPtr& req,
                  std::function<void(const HttpResponsePtr&)>&& callback,
                  const std::string& game_id);

private:
    // Logger.
    std::shared_ptr<LoggerBase> log_ = Logger::self();

    // Utility.
    std::shared_ptr<UtilBase> util_ = Util::self();
};

#endif  // CONTROLLERS_INIT_GAME_CONTROLLER_H