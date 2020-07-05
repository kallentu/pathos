#ifndef PATHOS_SKILL
#define PATHOS_SKILL

#include <string>

namespace Pathos {
  struct Skill {
    // Name of the skill, used for view.
    std::string name;

    // Multiplier on top of damage types from weapons.
    size_t physicalDamage;
    size_t magicDamage;

    Skill(std::string name, size_t physicalDamage, size_t magicDamage) : name{std::move(name)},
                                                                         physicalDamage{physicalDamage},
                                                                         magicDamage{magicDamage} {}

    // Override method for the display string after mob has used it.
    virtual std::string useSkillString(Mob *attacker, Mob *victim) const = 0;
  };
}

#endif // PATHOS_SKILL
