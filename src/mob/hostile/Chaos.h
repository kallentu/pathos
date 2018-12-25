#ifndef PATHOS_CHAOS
#define PATHOS_CHAOS

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Boss mob for level 55
class Chaos : public Hostile {
public:
  Chaos() : Hostile(20000000, 1000000) {}
  ~Chaos() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_CHAOS
