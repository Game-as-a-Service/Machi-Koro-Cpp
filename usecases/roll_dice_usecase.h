#pragma once

#include <string>

#include "../models/machikoro_game.h"
#include "game_repository.h"
#include "presenter.h"

// An input for RollDiceUsecase.
class RollDiceUsecaseRequest {
public:
    RollDiceUsecaseRequest(const std::string& name, int cnt)
        : player_name_(name)
        , rolled_dice_cnt_(cnt)
    {
    }

private:
    std::string player_name_;
    int rolled_dice_cnt_;
};

class RollDicePresenter : public Presenter {
public:
    void Present(const MachiKoroGame& game);
};

// TODO: 只要RollDice失敗一次，就直接幫他擲骰子。（壞）
class RollDiceUsecase {
public:
    void RollDiceExecute(const RollDiceUsecaseRequest& input,
        GameRepository& repo,
        Presenter& presenter
    );
};