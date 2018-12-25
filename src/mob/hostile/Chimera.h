#ifndef PATHOS_CHIMERA
#define PATHOS_CHIMERA

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Boss mob for level 25
class Chimera : public Hostile {
public:
  Chimera() : Hostile(25000, 800) {}
  ~Chimera() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_CHIMERA
