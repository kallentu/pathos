#include "mob/hostile/Arachne.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Arachne::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() && p.getDamage() > Hostile::getHealth()) {
    // Arachne killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getDamage());
  }
}

void Arachne::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(2000000);
  p.addDrachma(900000);
}
