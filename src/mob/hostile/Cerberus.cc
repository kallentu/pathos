#include "mob/hostile/Cerberus.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Cerberus::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() &&
      p.getMagicDamage() + (p.getPhysicalDamage() / 2) > Hostile::getHealth()) {
    // Cerberus killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getMagicDamage() -
                       (p.getPhysicalDamage() / 2));
  }
}

void Cerberus::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(25000);
  p.addDrachma(3000);
}
