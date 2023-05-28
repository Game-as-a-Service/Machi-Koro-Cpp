#include "convenient_store.h"

ConvenientStore::ConvenientStore() : 
    Building(CardName::CONVENIENCE_STORE, 2, CardType::SHOP, {4}, IndustryType::SECONDARY_INDUSTRY)
{
}

void ConvenientStore::OperateEffect(std::shared_ptr<Player>& owner,
    std::vector<std::shared_ptr<Player>>& players,
    std::shared_ptr<Bank>& bank)
{
    
}