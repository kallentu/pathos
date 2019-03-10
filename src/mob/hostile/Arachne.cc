#include "mob/hostile/Arachne.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Arachne::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() &&
      (p.getMagicDamage() / 10) + p.getPhysicalDamage() >
          Hostile::getHealth()) {
    // Arachne killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getPhysicalDamage() -
                       (p.getMagicDamage() / 10));
  }
}

void Arachne::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(2000000);
  p.addDrachma(900000);
}
