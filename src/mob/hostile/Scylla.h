#ifndef PATHOS_SCYLLA
#define PATHOS_SCYLLA

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Mob for level 15-25 area
class Scylla : public Hostile {
public:
  Scylla() : Hostile(5000, 400) {}
  ~Scylla() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_SCYLLA
