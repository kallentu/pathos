#include "mob/hostile/Wolf.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Wolf::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(15);
  p.addDrachma(20);
}
