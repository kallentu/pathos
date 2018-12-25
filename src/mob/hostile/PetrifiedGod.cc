#include "mob/hostile/PetrifiedGod.h"
#include "mob/player/Player.h"

using namespace Pathos;

void PetrifiedGod::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() && p.getDamage() > Hostile::getHealth()) {
    // PetrifiedGod killed.
    Hostile::setDeceased(true);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getDamage());
  }
}
