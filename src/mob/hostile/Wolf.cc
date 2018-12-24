#include "mob/hostile/Wolf.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Wolf::beAttackedBy(Player &p) {
  // TODO: special moves later.

  // Wolf killed
  if (!Hostile::isDeceased() && p.getDamage() > Hostile::getHealth()) {
    Hostile::setDeceased(true);
    // Take damage accordingly
  } else {
    Hostile::setHealth(Hostile::getHealth() - p.getDamage());
  }
}
