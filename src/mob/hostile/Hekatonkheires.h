#ifndef PATHOS_HEKATONKHEIRES
#define PATHOS_HEKATONKHEIRES

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Boss mob for level 44
class Hekatonkheires : public Hostile {
public:
  Hekatonkheires() : Hostile("Hekatonkheires", 1000000, 15000, 0) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_HEKATONKHEIRES
