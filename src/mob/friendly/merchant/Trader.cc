#include "mob/friendly/merchant/Trader.h"
#include "item/Item.h"
#include <memory>
#include <vector>

using namespace Pathos;

void Trader::buy(Item *it, Trader *other) {
  // Not enough drachma
  if (drachma < it->getSellPrice()) {
    // TODO: Trigger view error.
    return;
  } else if (other->findItem(it) == other->getInventory().end()) {
    // TODO: Throw more specific exception
    throw;
  }

  removeDrachma(it->getSellPrice());
  other->addDrachma(it->getSellPrice());

  auto itemIterator = other->findItem(it);
  addItemToInventory(std::move(*itemIterator));
  other->removeItemFromInventory(itemIterator);
}

void Trader::sell(Item *it, Trader *other) {
  // Buyer doesn't have enough drachma
  if (other->getDrachma() < it->getBuyPrice()) {
    return;
  } else if (findItem(it) == inventory.end()) {
    throw;
  }

  addDrachma(it->getBuyPrice());
  other->removeDrachma(it->getBuyPrice());

  auto itemIterator = findItem(it);
  other->addItemToInventory(std::move(*itemIterator));
  removeItemFromInventory(itemIterator);
}

void Trader::addItemToInventory(std::unique_ptr<Item> it) {
  inventory.push_back(std::move(it));
}

void Trader::removeItemFromInventory(
    std::vector<std::unique_ptr<Item>>::iterator it) {
  inventory.erase(it);
}

std::vector<std::unique_ptr<Item>>::iterator Trader::findItem(Item *it) {
  auto first = inventory.begin();
  auto last = inventory.end();
  while (first != last) {
    if ((*first)->equals(*it))
      return first;
    ++first;
  }
  return last;
}
