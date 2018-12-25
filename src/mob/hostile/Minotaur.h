#ifndef PATHOS_MINOTAUR
#define PATHOS_MINOTAUR

#include "mob/hostile/Hostile.h"

namespace Pathos {

// Boss mob for level 40
class Minotaur : public Hostile {
public:
  Minotaur() : Hostile(100000, 5000) {}
  ~Minotaur() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_MINOTAUR
