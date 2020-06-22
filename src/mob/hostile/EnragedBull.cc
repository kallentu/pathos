#include "mob/hostile/EnragedBull.h"
#include "mob/player/Player.h"

using namespace Pathos;

void EnragedBull::beKilledBy(Player &p) {
  p.addExperience(15000);
  p.addDrachma(7000);
}
