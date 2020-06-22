#include "mob/hostile/Wolf.h"
#include "mob/player/Player.h"
#include "state/Stats.h"

using namespace Pathos;

void Wolf::beKilledBy(Player &p) {
  p.addExperience(15);
  p.addDrachma(20);

  // Update the stat for wolves killed. See Gaia's quest.
  p.getStats()->wolvesKilled++;
}
