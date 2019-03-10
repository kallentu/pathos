#include "mob/hostile/Chimera.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Chimera::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() &&
      p.getMagicDamage() + p.getPhysicalDamage() > Hostile::getHealth()) {
    // Chimera killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getMagicDamage() -
                       p.getPhysicalDamage());
  }
}

void Chimera::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(5000);
  p.addDrachma(1250);
}
