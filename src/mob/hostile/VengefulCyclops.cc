#include "mob/hostile/VengefulCyclops.h"
#include "mob/player/Player.h"

using namespace Pathos;

void VengefulCyclops::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() &&
      p.getMagicDamage() + p.getPhysicalDamage() > Hostile::getHealth()) {
    // VengefulCyclops killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getMagicDamage() -
                       p.getPhysicalDamage());
  }
}

void VengefulCyclops::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(100000);
  p.addDrachma(35000);
}
