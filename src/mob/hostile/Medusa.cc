#include "mob/hostile/Medusa.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Medusa::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(1500000);
  p.addDrachma(100000);
}
