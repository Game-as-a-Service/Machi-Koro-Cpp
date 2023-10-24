#pragma once

#include <string>

#include "../models/machikoro_game.h"
#include "game_repository.h"
#include "presenter.h"

// An input for RollDiceUsecase.
class RollDiceUsecaseRequest {
public:
    RollDiceUsecaseRequest(const std::string& id,
                            const std::string& name,
                            int cnt)
        : game_id_(id)
        , player_name_(name)
        , rolled_dice_cnt_(cnt)
    {}

    std::string get_game_id() const { return game_id_; }

private:
    std::string game_id_;
    std::string player_name_;
    int rolled_dice_cnt_;
};

// TODO: 只要RollDice失敗一次，就直接幫他擲骰子。（壞）
class RollDiceUsecase {
public:
    void RollDiceExecute(const RollDiceUsecaseRequest& input,
        GameRepository& repo,
        Presenter& presenter
    );
};