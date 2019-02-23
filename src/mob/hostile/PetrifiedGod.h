#ifndef PATHOS_PETRIFIED_GOD
#define PATHOS_PETRIFIED_GOD

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Mob for level 46-48 area
class PetrifiedGod : public Hostile {
public:
  PetrifiedGod() : Hostile(1250000, 20000) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_PETRIFIED_GOD
