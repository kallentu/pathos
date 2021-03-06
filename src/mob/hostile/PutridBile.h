#ifndef PATHOS_PUTRID_BILE
#define PATHOS_PUTRID_BILE

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Mob for level 40-44 area
class PutridBile : public Hostile {
public:
  PutridBile() : Hostile("Putrid Bile", 150000, 7000, 500) {}

private:
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_PUTRID_BILE
