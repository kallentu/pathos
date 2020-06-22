#include "mob/hostile/PutridBile.h"
#include "mob/player/Player.h"

using namespace Pathos;


void PutridBile::beKilledBy(Player &p) {
  p.addExperience(30000);
  p.addDrachma(6750);
}
