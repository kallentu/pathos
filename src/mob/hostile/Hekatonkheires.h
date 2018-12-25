#ifndef PATHOS_HEKATONKHEIRES
#define PATHOS_HEKATONKHEIRES

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Boss mob for level 44
class Hekatonkheires : public Hostile {
public:
  Hekatonkheires() : Hostile(1000000, 15000) {}
  ~Hekatonkheires() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_HEKATONKHEIRES
