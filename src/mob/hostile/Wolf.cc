#include <combat/skill/Bite.h>
#include "mob/hostile/Wolf.h"
#include "mob/player/Player.h"
#include "state/Stats.h"

using namespace Pathos;

void Wolf::retaliate(Player &p, CombatManager &cm) {
  // TODO: Remove once we have basic combat finished (ie. add skills to all mobs)
  p.setHealth(p.getHealth() - 10);
}

void Wolf::beKilledBy(Player &p) {
  p.addExperience(15);
  p.addDrachma(20);

  // Update the stat for wolves killed. See Gaia's quest.
  p.getStats()->wolvesKilled++;
}
