#ifndef PATHOS_WEAPON
#define PATHOS_WEAPON

#include "item/equip/Equipable.h"
#include <string>

namespace Pathos {

// Used to attack other mobs, equipped by mobs to help them gain strength and
// damage.
// TODO: make weapons have item requirements to craft and build.
class Weapon : public Equipable {
  size_t damage;

public:
  Weapon(std::string namePostfix, size_t damage, size_t sellPrice,
         size_t buyPrice)
      : Equipable("weapon_" + namePostfix, sellPrice, buyPrice), damage{
                                                                     damage} {}

  size_t getDamage() { return damage; }
  void setDamage(size_t d) { damage = d; }
};

} // namespace Pathos

#endif // PATHOS_WEAPON
