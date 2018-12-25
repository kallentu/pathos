#ifndef PATHOS_CENTAUR
#define PATHOS_CENTAUR

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Mob for level 10-25 area
class Centaur : public Hostile {
public:
  Centaur() : Hostile(1200, 100) {}
  ~Centaur() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_CENTAUR
