#ifndef USECASES_CLEAR_GAME_H
#define USECASES_CLEAR_GAME_H

#include <string>
#include <memory>

#include "utils/util_base.h"
#include "loggers/logger_base.h"
#include "presenters/presenter.h"
#include "repos/repository.h"

class ClearGameRequest {
public:
    ClearGameRequest() = default;

    explicit ClearGameRequest(const std::string& id);

    ~ClearGameRequest() = default;

    std::string id() { return id_; }

private:
    // Game ID.
    std::string id_;
};

class ClearGameUsecase {
public:
    ClearGameUsecase(std::shared_ptr<LoggerBase> logger, std::shared_ptr<UtilBase> util);

    ~ClearGameUsecase() = default;

    // Find / Modify / Save / Push back.
    void execute(ClearGameRequest& req, Repository& repo, Presenter& presenter);

private:
    std::shared_ptr<LoggerBase> log_ = nullptr;

    std::shared_ptr<UtilBase> util_ = nullptr;
};

#endif  // USECASES_CLEAR_GAME_H