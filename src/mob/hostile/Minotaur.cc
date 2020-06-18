#include "mob/hostile/Minotaur.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Minotaur::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(50000);
  p.addDrachma(10000);
}
