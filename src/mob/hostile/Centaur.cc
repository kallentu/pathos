#include "mob/hostile/Centaur.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Centaur::beKilledBy(Player &p) {
  p.addExperience(20);
  p.addDrachma(115);
}
