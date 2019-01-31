#ifndef PATHOS_EQUIPABLE
#define PATHOS_EQUIPABLE

#include "item/Item.h"
#include <string>

namespace Pathos {

class Mob;

// Items that can be equipped.
// Example are weapons and armors.
class Equipable : public Item {
public:
  Equipable(std::string namePostfix, size_t sellPrice, size_t buyPrice)
      : Item("equip_" + namePostfix, sellPrice, buyPrice) {}

  virtual void beEquippedBy(Mob *m) = 0;
};

} // namespace Pathos

#endif // PATHOS_EQUIPABLE
