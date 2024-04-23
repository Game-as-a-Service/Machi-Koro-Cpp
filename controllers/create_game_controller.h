#ifndef CONTROLLERS_CREATE_GAME_CONTROLLER_H
#define CONTROLLERS_CREATE_GAME_CONTROLLER_H

#include <memory>

#include "drogon/HttpController.h"
#include "utils/util.h"
#include "loggers/logger.h"

class LoggerBase;
class UtilBase;

using namespace drogon;

class CreateGame : public drogon::HttpController<CreateGame> {
public:
    METHOD_LIST_BEGIN
    METHOD_ADD(CreateGame::createGame, "/", Post);
    METHOD_LIST_END

    void createGame(const HttpRequestPtr& req,
                    std::function<void(const HttpResponsePtr&)>&& callback);

private:
    // Logger.
    std::shared_ptr<LoggerBase> log_ = Logger::self();

    // Utility.
    std::shared_ptr<UtilBase> util_ = Util::self();
};

#endif  // CONTROLLERS_CREATE_GAME_CONTROLLER_H