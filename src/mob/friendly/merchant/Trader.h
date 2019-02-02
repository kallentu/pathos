#ifndef PATHOS_TRADER
#define PATHOS_TRADER

#include <memory>
#include <vector>

namespace Pathos {

class Item;

// Traders are able to trade items and drachma.
class Trader {
  size_t drachma;
  std::vector<std::unique_ptr<Item>> inventory;

public:
  Trader() : drachma{500} {}
  virtual ~Trader() {}

  std::vector<std::unique_ptr<Item>> &getInventory() { return inventory; }

  size_t getDrachma() const { return drachma; }
  void setDrachma(size_t d) { drachma = d; }

  void addDrachma(size_t d) { drachma += d; }
  void removeDrachma(size_t d) { drachma -= d; }

  void buy(Item *it, Trader *other);
  void sell(Item *it, Trader *other);

  void addItemToInventory(std::unique_ptr<Item> it);
  void removeItemFromInventory(std::vector<std::unique_ptr<Item>>::iterator it);

  // Returns nullptr if not found, otherwise iterator to unique_ptr of item.
  std::vector<std::unique_ptr<Item>>::iterator findItem(Item *it);
};

} // namespace Pathos

#endif // PATHOS_TRADER
