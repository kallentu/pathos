#ifndef PATHOS_ARACHNE
#define PATHOS_ARACHNE

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Boss mob for level 51
class Arachne : public Hostile {
public:
  Arachne() : Hostile(7000000, 75000) {}
  ~Arachne() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_ARACHNE
