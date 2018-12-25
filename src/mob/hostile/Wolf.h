#ifndef PATHOS_WOLF
#define PATHOS_WOLF

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Mob for level 1 to 10 area
class Wolf : public Hostile {
public:
  Wolf() : Hostile(100, 20) {}
  ~Wolf() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_WOLF
