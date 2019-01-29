#include "mob/friendly/merchant/Merchant.h"
#include "item/Item.h"
#include "mob/player/Player.h"
#include <algorithm>
#include <memory>
#include <vector>

using namespace Pathos;

void Merchant::buy(Item *it, Player *p) {
  // Not enough drachma
  if (drachma < it->getSellPrice()) {
    // TODO: Trigger something with view
    return;
  } else if (!p->hasItem(it)) {
    // TODO: Throw a more specific exception
    throw;
  }

  drachma -= it->getSellPrice();
  inventory.push_back(std::move(it));
}

void Merchant::sell(Item *it, Player *p) {
  // Player doesn't have enough drachma
  if (p->getDrachma() < it->getBuyPrice()) {
    // TODO: Trigger view warning
    return;
  } else if (!hasItem(it)) {
    // TODO: Throw a more specific exception
    throw;
  }

  drachma += it->getBuyPrice();

  // TODO: May need custom finder.
  auto item = std::find(inventory.begin(), inventory.end(), it);
  p->addItemToInventory(std::move(item));
  inventory.erase(item);
}
