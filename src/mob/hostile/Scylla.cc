#include "mob/hostile/Scylla.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Scylla::beKilledBy(Player &p) {
  p.addExperience(200);
  p.addDrachma(750);
}
