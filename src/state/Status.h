#ifndef PATHOS_STATUS
#define PATHOS_STATUS

#include <cstddef>
#include <string>

namespace Pathos {

// Access to the important statuses of the Pathos game.
  struct Status final {
    std::string playerName;
    size_t playerLevel;
    size_t playerMaxHealth, playerHealth;
    size_t playerMagicDamage, playerPhysicalDamage;
  };

} // namespace Pathos

#endif // PATHOS_STATUS
