#ifndef USECASES_ROLL_DICE_H
#define USECASES_ROLL_DICE_H

#include <string>
#include <memory>

class LoggerBase;
class Presenter;
class Repository;
class UtilBase;

class RollDiceRequest {
public:
    RollDiceRequest() = default;

    explicit RollDiceRequest(const std::string& id, const std::string& player_name, int dice_count);

    ~RollDiceRequest() = default;

    std::string id() { return id_; }

    std::string player_name() { return player_name_; }

    int dice_count() { return dice_count_; }

private:
    // Game ID.
    std::string id_;
    std::string player_name_;
    int dice_count_;
};

class RollDiceUsecase {
public:
    RollDiceUsecase(std::shared_ptr<LoggerBase> logger, std::shared_ptr<UtilBase> util);

    ~RollDiceUsecase() = default;

    // Find / Modify / Save / Push back.
    void execute(RollDiceRequest& req, Repository& repo, Presenter& presenter);

private:
    std::shared_ptr<LoggerBase> log_ = nullptr;

    std::shared_ptr<UtilBase> util_ = nullptr;
};

#endif  // USECASES_ROLL_DICE_H