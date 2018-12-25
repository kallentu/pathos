#ifndef PATHOS_PETRIFIED_GOD
#define PATHOS_PETRIFIED_GOD

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Mob for level 46-48 area
class PetrifiedGod : public Hostile {
public:
  PetrifiedGod() : Hostile(1250000, 20000) {}
  ~PetrifiedGod() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_PETRIFIED_GOD
