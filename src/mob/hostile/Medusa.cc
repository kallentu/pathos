#include "mob/hostile/Medusa.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Medusa::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() && p.getPhysicalDamage() > Hostile::getHealth()) {
    // Medusa killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getPhysicalDamage());
  }
}

void Medusa::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(1500000);
  p.addDrachma(100000);
}
