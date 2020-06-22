#include "mob/hostile/VengefulCyclops.h"
#include "mob/player/Player.h"

using namespace Pathos;

void VengefulCyclops::beKilledBy(Player &p) {
  p.addExperience(100000);
  p.addDrachma(35000);
}
