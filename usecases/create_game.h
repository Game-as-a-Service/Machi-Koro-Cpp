#ifndef USECASES_CREATE_GAME_H
#define USECASES_CREATE_GAME_H

#include <memory>
#include <string>
#include <vector>

#include "utils/util.h"
#include "loggers/logger.h"
#include "presenters/presenter.h"
#include "repos/repository.h"
#include "models/player.h"

class CreateGameRequest {
public:
    CreateGameRequest() = default;

    CreateGameRequest(const std::vector<std::string>& names);

    ~CreateGameRequest() = default;

    std::vector<Player> players();

private:
    // Player names.
    std::vector<std::string> names_;
};

class CreateGameUsecase {
public:
    CreateGameUsecase(std::shared_ptr<Logger> logger, std::shared_ptr<Util> util);

    ~CreateGameUsecase() = default;

    // Find / Modify / Save / Push back.
    void execute(CreateGameRequest& req, Repository& repo, Presenter& presenter);

private:
    std::shared_ptr<Logger> log_ = nullptr;

    std::shared_ptr<Util> util_ = nullptr;
};

#endif  // USECASES_CREATE_GAME_H