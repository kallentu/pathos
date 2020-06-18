#include "mob/hostile/Harpy.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Harpy::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(250000);
  p.addDrachma(37500);
}
