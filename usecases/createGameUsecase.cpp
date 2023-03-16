#include "createGameUsecase.h"

#include "../models/game_repository.h"

CreateGameUsecaseRequest::CreateGameUsecaseRequest(const std::vector<std::string>& names)
    : player_names_(names)
{
}

CreateGameUsecase::CreateGameExecute(const CreateGameUsecaseRequest &input, Output &output)
{
    auto game = GameRepository::self()->CreateGame(input.get_player_names());
    std::cout << "Create game for id: " << game->get_game_id() << std::endl;
    output.buildGameStatus(game);
}