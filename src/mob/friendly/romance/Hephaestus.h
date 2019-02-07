#ifndef PATHOS_HEPHAESTUS
#define PATHOS_HEPHAESTUS

#include "mob/friendly/romance/Romanceable.h"

namespace Pathos {

class Hephaestus : public Romanceable {
public:
  Hephaestus() : Romanceable() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_HEPHAESTUS
