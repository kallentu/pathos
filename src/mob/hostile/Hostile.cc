#include <mob/hostile/Hostile.h>
#include "mob/player/Player.h"

using namespace Pathos;

void Hostile::beAttackedBy(Player &p, CombatManager &cm, Skill &s) {
  if (!isDeceased()) {
    // Calculate the damage the mob will take.
    size_t physicalDamage = p.getPhysicalDamage() * s.physicalDamage;
    size_t magicDamage = p.getMagicDamage() * s.magicDamage;
    size_t totalDamage = physicalDamage + magicDamage;

    // TODO: Flesh out with defense on the different types of damages.
    if (totalDamage >= getHealth()) {
      // Flag as dead mob and distribute loot.
      setHealth(0);
      setDeceased(true);
      beKilledBy(p);
      return;
    } else {
      setHealth(getHealth() - (magicDamage + physicalDamage));

      // Always retaliate with another attack.
      retaliate(p, cm);
    }
  }
}
