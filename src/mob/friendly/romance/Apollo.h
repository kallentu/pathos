#ifndef PATHOS_APOLLO
#define PATHOS_APOLLO

#include "mob/friendly/romance/Romanceable.h"

namespace Pathos {

class Apollo : public Romanceable {
public:
  Apollo() : Romanceable() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_APOLLO
