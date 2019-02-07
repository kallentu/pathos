#ifndef PATHOS_TYCHE
#define PATHOS_TYCHE

#include "mob/friendly/romance/Romanceable.h"

namespace Pathos {

class Tyche : public Romanceable {
public:
  Tyche() : Romanceable() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_TYCHE
