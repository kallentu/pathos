#include "mob/hostile/Arachne.h"
#include "mob/player/Player.h"

using namespace Pathos;

void Arachne::beKilledBy(Player &p) {
  p.addExperience(2000000);
  p.addDrachma(900000);
}
