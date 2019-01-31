#ifndef PATHOS_MERCHANT
#define PATHOS_MERCHANT

#include "mob/friendly/Friendly.h"
#include <memory>
#include <vector>

namespace Pathos {

class Item;
class Player;

class Merchant : public Friendly {
protected:
  size_t drachma;
  std::vector<std::unique_ptr<Item>> inventory;

public:
  Merchant() : Friendly(), drachma{500} {}

  void buy(Item *it, Player *p);
  void sell(Item *it, Player *p);

private:
  virtual void initializeStock() = 0;

  // Checks merchant has item in stock.
  bool hasItem(Item *it) const;
};

} // namespace Pathos

#endif // PATHOS_MERCHANT
