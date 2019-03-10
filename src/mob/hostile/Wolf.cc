#include "mob/hostile/Wolf.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Wolf::beAttackedBy(Player &p) {
  // TODO: special moves later.

  if (!Hostile::isDeceased() &&
      p.getMagicDamage() + p.getPhysicalDamage() > Hostile::getHealth()) {
    // Wolf killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getMagicDamage() -
                       p.getPhysicalDamage());
  }
}

void Wolf::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(15);
  p.addDrachma(20);
}
