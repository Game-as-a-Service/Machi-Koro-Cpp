#ifndef CONTROLLERS_CREATE_GAME_CONTROLLER_H
#define CONTROLLERS_CREATE_GAME_CONTROLLER_H

#include <memory>

#include "drogon/HttpController.h"
#include "utils/util_impl.h"
#include "loggers/logger_impl.h"
#include "repos/memory_repository.h"

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
    std::shared_ptr<LoggerImpl> log_ = LoggerImpl::self();

    // Utility.
    std::shared_ptr<UtilImpl> util_ = UtilImpl::self();
};

#endif  // CONTROLLERS_CREATE_GAME_CONTROLLER_H