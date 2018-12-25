#ifndef PATHOS_ENRAGED_BULL
#define PATHOS_ENRAGED_BULL

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Mob for level 35-40 area
class EnragedBull : public Hostile {
public:
  EnragedBull() : Hostile(30000, 2000) {}
  ~EnragedBull() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_ENRAGED_BULL
