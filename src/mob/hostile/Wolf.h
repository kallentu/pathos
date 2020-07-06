#ifndef PATHOS_WOLF
#define PATHOS_WOLF

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Mob for level 1 to 10 area
class Wolf : public Hostile {
public:
  Wolf() : Hostile("Wolf", 100, 0, 20) {}

private:
  void retaliate(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_WOLF
