#ifndef PATHOS_CERBERUS
#define PATHOS_CERBERUS

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Boss mob for level 35
class Cerberus : public Hostile {
public:
  Cerberus() : Hostile(250000, 1500) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_CERBERUS
