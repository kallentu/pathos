#ifndef PATHOS_CRONUS
#define PATHOS_CRONUS

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Boss mob for level 50
class Cronus : public Hostile {
public:
  Cronus() : Hostile(5000000, 50000) {}
  ~Cronus() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_CRONUS
