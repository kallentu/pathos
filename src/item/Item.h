#ifndef PATHOS_ITEM
#define PATHOS_ITEM

#include <cstddef>
#include <string>

namespace Pathos {

class Item {
  std::string name;
  size_t sellPrice, buyPrice;

public:
  Item(std::string name, size_t sellPrice, size_t buyPrice)
      : name{name}, sellPrice{sellPrice}, buyPrice{buyPrice} {}
  virtual ~Item() {}

  std::string getName() const { return name; }
  size_t getSellPrice() const { return sellPrice; }
  size_t getBuyPrice() const { return buyPrice; }

  void setName(std::string n) { name = n; }
  void setSellPrice(size_t s) { sellPrice = s; }
  void setBuyPrice(size_t b) { buyPrice = b; }

  bool equals(Item &it) const { return it.getName().compare(name) == 0; }
};

} // namespace Pathos

#endif // PATHOS_ITEM
