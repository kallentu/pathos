#ifndef PATHOS_HARPY
#define PATHOS_HARPY

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Mob for level 49-53 area
class Harpy : public Hostile {
public:
  Harpy() : Hostile(2000000, 40000) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_HARPY
