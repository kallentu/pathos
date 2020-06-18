#include "mob/hostile/Cerberus.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Cerberus::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(25000);
  p.addDrachma(3000);
}
