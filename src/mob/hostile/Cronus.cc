#include "mob/hostile/Cronus.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Cronus::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() && p.getDamage() > Hostile::getHealth()) {
    // Cronus killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getDamage());
  }
}

void Cronus::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(1000000);
  p.addDrachma(100000);
}
