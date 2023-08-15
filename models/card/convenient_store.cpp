#include "convenient_store.h"

ConvenientStore::ConvenientStore() : 
    Building(CardName::CONVENIENCE_STORE, 2, CardType::SHOP, {4}, IndustryType::SECONDARY_INDUSTRY)
{
}

void ConvenientStore::OperateEffect(Player* owner,
    std::vector<Player*> players,
    Bank* bank)
{
    
}