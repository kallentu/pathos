#ifndef PATHOS_HARPY
#define PATHOS_HARPY

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Mob for level 49-53 area
class Harpy : public Hostile {
public:
  Harpy() : Hostile(2000000, 40000) {}
  ~Harpy() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_HARPY
