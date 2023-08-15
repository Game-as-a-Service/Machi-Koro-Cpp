#include "create_game_usecase.h"

#include <iostream>

#include "game_repository.h"
#include "../models/machikoro_game.h"

CreateGameUsecaseRequest::CreateGameUsecaseRequest(const std::vector<std::string>& names)
    : player_names_(names)
{
}

void CreateGameUsecase::CreateGameExecute(const CreateGameUsecaseRequest &input, CreateGameUsecase::Presenter &presenter)
{
    auto game = std::make_shared<MachiKoroGame>(input.get_player_names());
    GameRepository::self().AddGame(game); // similar to presenter, but for different target
    presenter.Present(*game); // similar to repository
    // auto game = GameRepository::self().CreateGame(input.get_player_names());
    // presenter.Present(*game);
}
