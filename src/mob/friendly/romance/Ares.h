#ifndef PATHOS_ARES
#define PATHOS_ARES

#include "mob/friendly/romance/Romanceable.h"

namespace Pathos {

class Ares : public Romanceable {
public:
  Ares() : Romanceable() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_ARES
