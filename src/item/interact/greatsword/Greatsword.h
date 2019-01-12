#ifndef PATHOS_GREATSWORD
#define PATHOS_GREATSWORD

#include "item/interact/Weapon.h"
#include "mob/Mob.h"

namespace Pathos {

// A short-ranged weapon, high damage, medium speed.
class Greatsword : public Weapon {
public:
  Greatsword(size_t damage, size_t sellPrice, size_t buyPrice)
      : Weapon(damage, sellPrice, buyPrice) {}

  void beInteractedBy(Mob *m) override { m->interactWith(*this); }
};

} // namespace Pathos

#endif // PATHOS_GREATSWORD
