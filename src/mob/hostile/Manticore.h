#ifndef PATHOS_MANTICORE
#define PATHOS_MANTICORE

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Mob for level 53-55 area
class Manticore : public Hostile {
public:
  Manticore() : Hostile(6000000, 60000) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_MANTICORE
