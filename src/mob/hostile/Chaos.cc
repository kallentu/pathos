#include "mob/hostile/Chaos.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Chaos::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(5000000);
  p.addDrachma(250000);
}
