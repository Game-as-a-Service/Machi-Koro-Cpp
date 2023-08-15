#pragma once

#include <string>
#include <vector>

#include "../models/machikoro_game.h"
#include "game_repository.h"

// An input for CreateGameUsecase.
class CreateGameUsecaseRequest {
public:
    CreateGameUsecaseRequest() = default;
    CreateGameUsecaseRequest(const std::vector<std::string>& names);
    CreateGameUsecaseRequest(const CreateGameUsecaseRequest& uc) = delete;
    CreateGameUsecaseRequest(CreateGameUsecaseRequest&& uc) = delete;
    ~CreateGameUsecaseRequest() = default;

    void set_player_names(const std::vector<std::string>& names) { player_names_ = names; }
    std::vector<std::string> get_player_names() const { return player_names_; }

private:
    std::vector<std::string> player_names_;
};

class CreateGameUsecase {
public:
    class Presenter {
    public:
        virtual void Present(const MachiKoroGame& game) = 0;
    };

    CreateGameUsecase() = default;
    CreateGameUsecase(const CreateGameUsecase& uc) = delete;
    CreateGameUsecase(CreateGameUsecase&& uc) = delete;
    ~CreateGameUsecase() = default;

    void CreateGameExecute(const CreateGameUsecaseRequest& input, 
        GameRepository& repo, 
        Presenter& presenter);
};
