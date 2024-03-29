#ifndef USECASES_CREATE_GAME_H
#define USECASES_CREATE_GAME_H

#include <memory>
#include <string>
#include <vector>

#include "utils/util_base.h"
#include "loggers/logger_base.h"
#include "presenters/presenter.h"
#include "repos/repository.h"
#include "models/player.h"

class CreateGameRequest {
public:
    CreateGameRequest() = default;

    explicit CreateGameRequest(const std::vector<std::string>& names);

    ~CreateGameRequest() = default;

    std::vector<PlayerPtr> players();

private:
    // Player names.
    std::vector<std::string> names_;
};

class CreateGameUsecase {
public:
    CreateGameUsecase(std::shared_ptr<LoggerBase> logger, std::shared_ptr<UtilBase> util);

    ~CreateGameUsecase() = default;

    // Find / Modify / Save / Push back.
    void execute(CreateGameRequest& req, Repository& repo, Presenter& presenter);

private:
    std::shared_ptr<LoggerBase> log_ = nullptr;

    std::shared_ptr<UtilBase> util_ = nullptr;
};

#endif  // USECASES_CREATE_GAME_H