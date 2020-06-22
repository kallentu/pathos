#include "mob/hostile/PetrifiedGod.h"
#include "mob/player/Player.h"

using namespace Pathos;

void PetrifiedGod::beKilledBy(Player &p) {
  p.addExperience(300000);
  p.addDrachma(40000);
}
