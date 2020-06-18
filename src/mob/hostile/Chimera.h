#ifndef PATHOS_CHIMERA
#define PATHOS_CHIMERA

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Boss mob for level 25
class Chimera : public Hostile {
public:
  Chimera() : Hostile("Chimera", 25000, 100, 700) {}

private:
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_CHIMERA
