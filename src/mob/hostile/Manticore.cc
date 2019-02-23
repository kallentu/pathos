#include "mob/hostile/Manticore.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Manticore::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() && p.getDamage() > Hostile::getHealth()) {
    // Manticore killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getDamage());
  }
}

void Manticore::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(750000);
  p.addDrachma(50000);
}
