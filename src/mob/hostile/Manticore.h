#ifndef PATHOS_MANTICORE
#define PATHOS_MANTICORE

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Mob for level 53-55 area
class Manticore : public Hostile {
public:
  Manticore() : Hostile(6000000, 60000) {}
  ~Manticore() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_MANTICORE
