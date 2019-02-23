#ifndef PATHOS_CHAOS
#define PATHOS_CHAOS

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Boss mob for level 55
class Chaos : public Hostile {
public:
  Chaos() : Hostile(20000000, 1000000) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_CHAOS
