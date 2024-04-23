#ifndef USECASES_INIT_GAME_H
#define USECASES_INIT_GAME_H

#include <string>
#include <memory>

class LoggerBase;
class Presenter;
class Repository;
class UtilBase;

class InitGameRequest {
public:
    InitGameRequest() = default;

    explicit InitGameRequest(const std::string& id);

    ~InitGameRequest() = default;

    std::string id() { return id_; }

private:
    // Game ID.
    std::string id_;
};

class InitGameUsecase {
public:
    InitGameUsecase(std::shared_ptr<LoggerBase> logger, std::shared_ptr<UtilBase> util);

    ~InitGameUsecase() = default;

    // Find / Modify / Save / Push back.
    void execute(InitGameRequest& req, Repository& repo, Presenter& presenter);

private:
    std::shared_ptr<LoggerBase> log_ = nullptr;

    std::shared_ptr<UtilBase> util_ = nullptr;
};

#endif  // USECASES_INIT_GAME_H