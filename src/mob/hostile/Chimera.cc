#include "mob/hostile/Chimera.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Chimera::beKilledBy(Player &p) {
  p.addExperience(5000);
  p.addDrachma(1250);
}
