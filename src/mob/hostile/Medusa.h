#ifndef PATHOS_MEDUSA
#define PATHOS_MEDUSA

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Boss mob for level 53
class Medusa : public Hostile {
public:
  Medusa() : Hostile(10000000, 100000) {}
  ~Medusa() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_MEDUSA
