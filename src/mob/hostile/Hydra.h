#ifndef PATHOS_HYDRA
#define PATHOS_HYDRA

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Mob for level 25-35 area
class Hydra : public Hostile {
public:
  Hydra() : Hostile(10000, 800) {}
  ~Hydra() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_HYDRA
