#ifndef PATHOS_HERMES
#define PATHOS_HERMES

#include "mob/friendly/romance/Romanceable.h"

namespace Pathos {

class Hermes : public Romanceable {
public:
  Hermes() : Romanceable() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_HERMES
