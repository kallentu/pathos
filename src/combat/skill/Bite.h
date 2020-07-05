#ifndef PATHOS_BITE
#define PATHOS_BITE

#include <mob/Mob.h>
#include "combat/skill/Skill.h"

namespace Pathos {
  class Bite : public Skill {
  public:
    Bite() : Skill("Bite", 10, 0) {}
    std::string useSkillString(Mob *attacker, Mob *victim) const override {
      return attacker->getName() + " viciously bites " + victim->getName() + " for " + std::to_string(attacker->getPhysicalDamage() * physicalDamage) + " damage.";
    }
  };
}

#endif //PATHOS_BITE
