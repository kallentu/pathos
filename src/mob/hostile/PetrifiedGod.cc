#include "mob/hostile/PetrifiedGod.h"
#include "mob/player/Player.h"

using namespace Pathos;

void PetrifiedGod::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(300000);
  p.addDrachma(40000);
}
