#pragma once

#include <string>
#include <vector>

#include "common.h"

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
    std::vector<string> player_names_;
};

class CreateGameUsecase {
public:
    CreateGameUsecase() = default;
    CreateGameUsecase(const CreateGameUsecase& uc) = delete;
    CreateGameUsecase(CreateGameUsecase&& uc) = delete;
    ~CreateGameUsecase();

    CreateGameExecute(const CreateGameUsecaseRequest& input, Output& output);

};
