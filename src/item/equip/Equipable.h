#ifndef PATHOS_EQUIPABLE
#define PATHOS_EQUIPABLE

#include "item/Item.h"

namespace Pathos {

class Mob;

// Items that can be equipped.
// Example are weapons and armors.
class Equipable : public Item {
public:
  Equipable(size_t sellPrice, size_t buyPrice) : Item(sellPrice, buyPrice) {}

  virtual void beEquippedBy(Mob *m) = 0;
};

} // namespace Pathos

#endif // PATHOS_EQUIPABLE
