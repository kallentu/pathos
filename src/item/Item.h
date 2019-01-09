#ifndef PATHOS_ITEM
#define PATHOS_ITEM

#include <cstddef>

namespace Pathos {

class Item {
  size_t sellPrice, buyPrice;

public:
  Item(size_t sellPrice, size_t buyPrice)
      : sellPrice{sellPrice}, buyPrice{buyPrice} {}
  virtual ~Item() {}

  size_t getSellPrice() const { return sellPrice; }
  size_t getBuyPrice() const { return buyPrice; }

  void setSellPrice(size_t s) { sellPrice = s; }
  void setBuyPrice(size_t b) { buyPrice = b; }
};

} // namespace Pathos

#endif // PATHOS_ITEM
