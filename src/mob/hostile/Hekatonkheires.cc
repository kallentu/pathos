#include "mob/hostile/Hekatonkheires.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Hekatonkheires::beAttackedBy(Player &p) {
  if (!Hostile::isDeceased() && p.getDamage() > Hostile::getHealth()) {
    // Hekatonkheires killed.
    Hostile::setDeceased(true);
  } else if (!Hostile::isDeceased()) {
    // Attack if not dead.
    Hostile::setHealth(Hostile::getHealth() - p.getDamage());
  }
}
