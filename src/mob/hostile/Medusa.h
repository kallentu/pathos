#ifndef PATHOS_MEDUSA
#define PATHOS_MEDUSA

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Boss mob for level 53
class Medusa : public Hostile {
public:
  Medusa() : Hostile("Medusa", 10000000, 90000, 10000) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_MEDUSA
