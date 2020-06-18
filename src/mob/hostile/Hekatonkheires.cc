#include "mob/hostile/Hekatonkheires.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Hekatonkheires::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(200000);
  p.addDrachma(50000);
}
