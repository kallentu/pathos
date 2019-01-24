#ifndef PATHOS_BOW
#define PATHOS_BOW

#include "item/equip/Weapon.h"
#include "mob/Mob.h"

namespace Pathos {

// A long ranged weapon, low damage, fast speed.
class Bow : public Weapon {
public:
  Bow(size_t damage, size_t sellPrice, size_t buyPrice)
      : Weapon(damage, sellPrice, buyPrice) {}

  void beEquippedBy(Mob *m) override { m->equip(*this); }
};

} // namespace Pathos

#endif // PATHOS_BOW
