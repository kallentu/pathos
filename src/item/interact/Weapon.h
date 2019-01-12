#ifndef PATHOS_WEAPON
#define PATHOS_WEAPON

#include "item/interact/Interactable.h"

namespace Pathos {

// Used to attack other mobs, interacts with mobs to help them gain strength and
// damage.
class Weapon : public Interactable {
  size_t damage;

public:
  Weapon(size_t damage, size_t sellPrice, size_t buyPrice)
      : Interactable(sellPrice, buyPrice), damage{damage} {}

  size_t getDamage() { return damage; }
  void setDamage(size_t d) { damage = d; }
};

} // namespace Pathos

#endif // PATHOS_WEAPON
