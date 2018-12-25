#include "mob/hostile/PutridBile.h"
#include "mob/player/Player.h"

using namespace Pathos;

void PutridBile::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() && p.getDamage() > Hostile::getHealth()) {
    // PutridBile killed.
    Hostile::setDeceased(true);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getDamage());
  }
}
