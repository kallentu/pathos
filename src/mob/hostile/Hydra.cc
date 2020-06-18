#include "mob/hostile/Hydra.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Hydra::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(4000);
  p.addDrachma(1250);
}
