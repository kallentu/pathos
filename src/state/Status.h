#ifndef PATHOS_STATUS
#define PATHOS_STATUS

#include <cstddef>

namespace Pathos {

// Access to the important statuses of the Pathos game.
struct Status final {
  size_t playerMaxHealth, playerHealth;
};

} // namespace Pathos

#endif // PATHOS_STATUS
