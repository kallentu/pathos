#ifndef PATHOS_STAFF
#define PATHOS_STAFF

#include "item/equip/Weapon.h"
#include "mob/Mob.h"
#include <string>

namespace Pathos {

// A mid-ranged magical weapon, medium damage, but slow.
class Staff : public Weapon {
public:
  Staff(std::string namePostfix, size_t damage, size_t sellPrice,
        size_t buyPrice)
      : Weapon("staff_" + namePostfix, damage, sellPrice, buyPrice) {}

  void beEquippedBy(Mob *m) override { m->equip(*this); }
};

} // namespace Pathos

#endif // PATHOS_STAFF
