#ifndef PATHOS_APHRODITE
#define PATHOS_APHRODITE

#include "mob/friendly/romance/Romanceable.h"

namespace Pathos {

class Aphrodite : public Romanceable {
public:
  Aphrodite() : Romanceable() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_APHRODITE
