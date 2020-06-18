#ifndef PATHOS_CENTAUR
#define PATHOS_CENTAUR

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Mob for level 10-25 area
class Centaur : public Hostile {
public:
  Centaur() : Hostile("Centaur", 1200, 50, 50) {}

private:
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_CENTAUR
