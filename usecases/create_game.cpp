#include "create_game.h"

#include <memory>
#include <vector>
#include <string>

#include "loggers/logger_base.h"
#include "models/dice.h"
#include "models/machikoro_game.h"
#include "presenters/presenter.h"
#include "repos/repository.h"
#include "utils/util_base.h"

CreateGameRequest::CreateGameRequest(const std::vector<std::string>& names)
    : names_(names)
{
}

std::vector<PlayerPtr> CreateGameRequest::players()
{
    // TODO: 有關骰子的部分，到底要在哪裡塞進遊戲裡（為了假骰子、做測試），待商確。
    std::vector<PlayerPtr> players;
    auto dice = std::make_shared<Dice>();
    for (const auto& name : names_) players.emplace_back(std::make_unique<Player>(name, dice));
    return players;
}

CreateGameUsecase::CreateGameUsecase(std::shared_ptr<LoggerBase> logger,
                                     std::shared_ptr<UtilBase> util)
    : log_(logger)
    , util_(util)
{
}

void CreateGameUsecase::execute(CreateGameRequest& req, Repository& repo, Presenter& presenter)
{
    // Find.
    auto game = std::make_unique<MachiKoroGame>(log_, util_);

    // Modify.
    auto event = game->createGame(std::move(req.players()));

    // Save.
    if (event->status() == StatusCode::Ok) repo.save(std::move(game));

    // Push back.
    presenter.present(event.get());
}