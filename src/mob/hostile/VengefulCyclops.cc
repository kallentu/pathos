#include "mob/hostile/VengefulCyclops.h"
#include "mob/player/Player.h"

using namespace Pathos;

void VengefulCyclops::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() && p.getDamage() > Hostile::getHealth()) {
    // VengefulCyclops killed.
    Hostile::setDeceased(true);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getDamage());
  }
}
