#ifndef PATHOS_MANTICORE
#define PATHOS_MANTICORE

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Mob for level 53-55 area
class Manticore : public Hostile {
public:
  Manticore() : Hostile("Manticore", 6000000, 30000, 30000) {}

private:
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_MANTICORE
