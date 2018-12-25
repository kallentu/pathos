#ifndef PATHOS_CERBERUS
#define PATHOS_CERBERUS

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Boss mob for level 35
class Cerberus : public Hostile {
public:
  Cerberus() : Hostile(250000, 1500) {}
  ~Cerberus() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_CERBERUS
