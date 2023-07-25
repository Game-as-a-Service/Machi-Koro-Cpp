#include "create_game_usecase.h"

#include <iostream>

#include "../models/game_repository.h"

CreateGameUsecaseRequest::CreateGameUsecaseRequest(const std::vector<std::string>& names)
    : player_names_(names)
{
}

void CreateGameUsecase::CreateGameExecute(const CreateGameUsecaseRequest &input, CreateGameUsecase::Presenter &presenter)
{
    // Should create game first, and then store it into repository
    //TODO: add this
    /*
    auto game = Game(input);
    GameRepository::self().AddGame(game); // similar to presenter, but for different target
    presenter.present(game); // similar to repository
    */

    auto game = GameRepository::self().CreateGame(input.get_player_names());
    presenter.Present(*game.get());
}
