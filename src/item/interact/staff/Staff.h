#ifndef PATHOS_STAFF
#define PATHOS_STAFF

#include "item/interact/Weapon.h"
#include "mob/Mob.h"

namespace Pathos {

// A mid-ranged magical weapon, medium damage, but slow.
class Staff : public Weapon {
public:
  Staff(size_t damage, size_t sellPrice, size_t buyPrice)
      : Weapon(damage, sellPrice, buyPrice) {}

  void beInteractedBy(Mob *m) override { m->interactWith(*this); }
};

} // namespace Pathos

#endif // PATHOS_STAFF
