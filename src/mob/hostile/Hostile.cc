#include <mob/hostile/Hostile.h>
#include "mob/player/Player.h"

using namespace Pathos;

void Hostile::beAttackedBy(Player &p, Skill &s) {
  if (!isDeceased()) {
    // Calculate the damage the mob will take.
    size_t physicalDamage = p.getPhysicalDamage() * s.physicalDamage;
    size_t magicDamage = p.getMagicDamage() * s.magicDamage;

    // TODO: Flesh out with defense on the different types of damages.
    setHealth(getHealth() - (magicDamage + physicalDamage));

    // Optional: Special retaliation (before death).
    retaliate(p);

    // Flag as dead mob and distribute loot.
    if (getHealth() <= 0) {
      setDeceased(true);
      beKilledBy(p);
    }
  }
}
