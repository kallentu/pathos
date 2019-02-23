#ifndef PATHOS_PUTRID_BILE
#define PATHOS_PUTRID_BILE

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Mob for level 40-44 area
class PutridBile : public Hostile {
public:
  PutridBile() : Hostile(150000, 7500) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_PUTRID_BILE
