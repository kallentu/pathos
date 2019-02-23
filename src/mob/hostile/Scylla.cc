#include "mob/hostile/Scylla.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Scylla::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() && p.getDamage() > Hostile::getHealth()) {
    // Scylla killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getDamage());
  }
}

void Scylla::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(200);
  p.addDrachma(750);
}
