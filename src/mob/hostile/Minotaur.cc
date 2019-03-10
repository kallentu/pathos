#include "mob/hostile/Minotaur.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Minotaur::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() &&
      p.getMagicDamage() + p.getPhysicalDamage() > Hostile::getHealth()) {
    // Minotaur killed.
    Hostile::setDeceased(true);
    beKilledBy(p);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getMagicDamage() -
                       p.getPhysicalDamage());
  }
}

void Minotaur::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(50000);
  p.addDrachma(10000);
}
