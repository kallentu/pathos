#include "mob/hostile/Cronus.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Cronus::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(1000000);
  p.addDrachma(100000);
}
