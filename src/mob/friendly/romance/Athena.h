#ifndef PATHOS_ATHENA
#define PATHOS_ATHENA

#include "mob/friendly/romance/Romanceable.h"

namespace Pathos {

class Athena : public Romanceable {
public:
  Athena() : Romanceable() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_ATHENA
