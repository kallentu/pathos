#include <combat/skill/Bite.h>
#include "mob/hostile/Wolf.h"
#include "mob/player/Player.h"
#include "state/Stats.h"

using namespace Pathos;

void Wolf::retaliate(Player &p) {
  // TODO: Generate actual skills for Wolf.
  p.setHealth(p.getHealth() - 10);
  CombatManager::instance()->addHostileAttackLog(this, Bite().useSkillString(dynamic_cast<Mob *>(this), &p));
}

void Wolf::beKilledBy(Player &p) {
  p.addExperience(15);
  p.addDrachma(20);

  // Update the stat for wolves killed. See Gaia's quest.
  p.getStats()->wolvesKilled++;
}
