#include "mob/hostile/Hydra.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Hydra::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() &&
      p.getMagicDamage() + p.getPhysicalDamage() > Hostile::getHealth()) {
    // Hydra killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getMagicDamage() -
                       p.getPhysicalDamage());
  }
}

void Hydra::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(4000);
  p.addDrachma(1250);
}
