#ifndef PATHOS_SCYLLA
#define PATHOS_SCYLLA

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Mob for level 15-25 area
class Scylla : public Hostile {
public:
  Scylla() : Hostile(5000, 400) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_SCYLLA
