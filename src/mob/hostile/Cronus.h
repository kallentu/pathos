#ifndef PATHOS_CRONUS
#define PATHOS_CRONUS

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Boss mob for level 50
class Cronus : public Hostile {
public:
  Cronus() : Hostile(5000000, 50000) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_CRONUS
