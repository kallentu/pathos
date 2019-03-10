#include "mob/hostile/Harpy.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Harpy::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() &&
      p.getMagicDamage() + p.getPhysicalDamage() > Hostile::getHealth()) {
    // Harpy killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getMagicDamage() -
                       p.getPhysicalDamage());
  }
}

void Harpy::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(250000);
  p.addDrachma(37500);
}
