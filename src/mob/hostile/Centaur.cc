#include "mob/hostile/Centaur.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Centaur::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() && p.getDamage() > Hostile::getHealth()) {
    // Centaur killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getDamage());
  }
}

void Centaur::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(20);
  p.addDrachma(115);
}
