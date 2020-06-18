#include "mob/hostile/Manticore.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Manticore::beKilledBy(Player &p) {
  // TODO: Send KillRequest
  p.addExperience(750000);
  p.addDrachma(50000);
}
