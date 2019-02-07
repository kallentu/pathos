#ifndef PATHOS_ARTEMIS
#define PATHOS_ARTEMIS

#include "mob/friendly/romance/Romanceable.h"

namespace Pathos {

class Artemis : public Romanceable {
public:
  Artemis() : Romanceable() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_ARTEMIS
