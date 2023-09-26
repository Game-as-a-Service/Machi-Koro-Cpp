#include "roll_dice_usecase.h"

void RollDiceUsecase::RollDiceExecute(const RollDiceUsecaseRequest& input,
                                    GameRepository& repo,
                                    Presenter& presenter)
{
    // 查
    auto game = repo.FindGameByID(input.get_game_id());
    // 改

}