#ifndef PATHOS_HYDRA
#define PATHOS_HYDRA

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Mob for level 25-35 area
class Hydra : public Hostile {
public:
  Hydra() : Hostile("Hydra", 10000, 800, 0) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_HYDRA
