#ifndef PATHOS_VENGEFUL_CYCLOPS
#define PATHOS_VENGEFUL_CYCLOPS

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Mob for level 44-48 area
class VengefulCyclops : public Hostile {
public:
  VengefulCyclops() : Hostile("Vengeful Cyclops", 750000, 5000, 6500) {}

private:
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_VENGEFUL_CYCLOPS
