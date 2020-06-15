#ifndef PATHOS_SKILL
#define PATHOS_SKILL

#include <string>

namespace Pathos {
  struct Skill {
    // Name of the skill, used for view.
    std::string name;

    // Damage before weapon multiplier.
    size_t damage;
  };
}

#endif //PATHOS_SKILL
