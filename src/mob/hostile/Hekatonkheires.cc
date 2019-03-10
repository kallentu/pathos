#include "mob/hostile/Hekatonkheires.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Hekatonkheires::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() &&
      p.getMagicDamage() + p.getPhysicalDamage() > Hostile::getHealth()) {
    // Hekatonkheires killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getMagicDamage() -
                       p.getPhysicalDamage());
  }
}

void Hekatonkheires::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(200000);
  p.addDrachma(50000);
}
