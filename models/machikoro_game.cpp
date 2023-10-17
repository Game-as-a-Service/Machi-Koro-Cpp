#include "machikoro_game.h"

#include <iostream>

#include "events/roll_dice_event.h"

MachiKoroGame::MachiKoroGame(const std::vector<std::string>& player_names)
{
    for (const auto& name : player_names)
    {
        auto player = std::make_unique<Player>(name);
        players_.push_back(std::move(player));
    }

    bank_ = std::make_unique<Bank>();
    for (auto& player : players_)
        bank_->PayCoin2Player(3, player.get());

    market_ = std::make_unique<ArchitectureMarket>();

    for (auto& player : players_) {
        player->GainInitialBuildings(std::move(market_->GetInitialBuildingsForOnePlayer()));
        player->GainLandmarks(std::move(market_->GetLandmarksForOnePlayer()));
    }

    // Choose one player as starter

}

MachiKoroGame::~MachiKoroGame()
{
    bank_ = nullptr;
    market_ = nullptr;
    for (auto& p : players_)
        p = nullptr;
    players_.clear();
}

void MachiKoroGame::GameStart()
{
    std::cout << "Game Start !!" << std::endl;
}

std::vector<Player*> MachiKoroGame::get_players()
{
    std::vector<Player*> players;
    for (const auto& player: players_)
        players.push_back(player.get());
    return players;
}

std::unique_ptr<DomainEvent> 
MachiKoroGame::RollDice(const std::string& player_id, int dice_count) 
{
    auto IsLandmarkInHand = 
        [](const Hand* hand, CardName name) -> bool {
            auto it = std::find(
                hand->get_landmarks().begin(),
                hand->get_landmarks().end(),
                [](const auto& landmark)  { 
                    return landmark->get_name() == name &&
                        landmark->IsActive(); 
                }
            );
            return it != hand->get_landmarks().end();
        };
    
    // Idnetify current player.
    auto player = (*std::find_if(players_.begin(), players_.end(),
        [](const auto& p) { return p->get_name() == player_id; }
    )).get();

    auto [pt1, pt2] = player->RollDice(dice_count);
    auto event = std::make_unique<RollDiceEvent>(pt1, pt2,
        !(dice_count == 2 && pt2 == 0));
    if (IsLandmarkInHand(player->get_hand(), CardName::RADIO_TOWER))
    {
        // Can reroll the dice or not.
        event->set_can_reroll(true);
        return event;
    }

    // Operate effect. 

    // If two points are the same, can roll the dice in next round or not.
    if (pt1 == pt2 &&
        IsLandmarkInHand(player->get_hand(), CardName::AMUSEMENT_PARK))
    {

    }
    return event;
}