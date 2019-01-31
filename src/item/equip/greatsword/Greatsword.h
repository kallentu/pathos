#ifndef PATHOS_GREATSWORD
#define PATHOS_GREATSWORD

#include "item/equip/Weapon.h"
#include "mob/Mob.h"
#include <string>

namespace Pathos {

// A short-ranged weapon, high damage, medium speed.
class Greatsword : public Weapon {
public:
  Greatsword(std::string namePostfix, size_t damage, size_t sellPrice,
             size_t buyPrice)
      : Weapon("greatsword_" + namePostfix, damage, sellPrice, buyPrice) {}

  void beEquippedBy(Mob *m) override { m->equip(*this); }
};

} // namespace Pathos

#endif // PATHOS_GREATSWORD
