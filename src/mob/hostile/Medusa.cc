#include "mob/hostile/Medusa.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Medusa::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() && p.getDamage() > Hostile::getHealth()) {
    // Medusa killed.
    Hostile::setDeceased(true);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getDamage());
  }
}
