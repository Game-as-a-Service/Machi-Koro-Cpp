#include "convenient_store.h"

#include "models/bank.h"
#include "models/player.h"

ConvenientStore::ConvenientStore()
    : Building(CardName::CONVENIENCE_STORE,
               CardType::SHOP,
               2,
               IndustryType::SECONDARY_INDUSTRY,
               { 4 })
{
}

void ConvenientStore::doOperateEffect(Player* owner,
                                    Player* dice_roller,
                                    std::vector<Player*> players,
                                    Bank* bank)
{
}