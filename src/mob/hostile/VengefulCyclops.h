#ifndef PATHOS_VENGEFUL_CYCLOPS
#define PATHOS_VENGEFUL_CYCLOPS

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Mob for level 44-48 area
class VengefulCyclops : public Hostile {
public:
  VengefulCyclops() : Hostile(750000, 11500) {}
  ~VengefulCyclops() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_VENGEFUL_CYCLOPS
