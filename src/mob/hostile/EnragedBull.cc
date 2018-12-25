#include "mob/hostile/EnragedBull.h"
#include "mob/player/Player.h"

using namespace Pathos;

void EnragedBull::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() && p.getDamage() > Hostile::getHealth()) {
    // EnragedBull killed.
    Hostile::setDeceased(true);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getDamage());
  }
}
