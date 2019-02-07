#ifndef PATHOS_DIONYSUS
#define PATHOS_DIONYSUS

#include "mob/friendly/romance/Romanceable.h"

namespace Pathos {

class Dionysus : public Romanceable {
public:
  Dionysus() : Romanceable() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_DIONYSUS
