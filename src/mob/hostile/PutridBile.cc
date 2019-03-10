#include "mob/hostile/PutridBile.h"
#include "mob/player/Player.h"

using namespace Pathos;

void PutridBile::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() &&
      p.getMagicDamage() + p.getPhysicalDamage() > Hostile::getHealth()) {
    // PutridBile killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getMagicDamage() -
                       p.getPhysicalDamage());
  }
}

void PutridBile::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(30000);
  p.addDrachma(6750);
}
