#include "create_game_usecase.h"

#include <iostream>

#include "../models/game_repository.h"

CreateGameUsecaseRequest::CreateGameUsecaseRequest(const std::vector<std::string>& names)
    : player_names_(names)
{
}

void CreateGameUsecase::CreateGameExecute(const CreateGameUsecaseRequest &input, Output &output)
{
    auto game = GameRepository::self().CreateGame(input.get_player_names());
    output.BuildGameStatus(game);
}