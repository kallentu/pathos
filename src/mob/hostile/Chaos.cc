#include "mob/hostile/Chaos.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Chaos::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() &&
      (p.getMagicDamage() / 2) + (p, getPhysicalDamage() / 2) >
          Hostile::getHealth()) {
    // Chaos killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - (p.getMagicDamage() / 2) -
                       (p.getPhysicalDamage() / 2));
  }
}

void Chaos::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(5000000);
  p.addDrachma(250000);
}
