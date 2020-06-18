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
  };
}

#endif // PATHOS_SKILL
