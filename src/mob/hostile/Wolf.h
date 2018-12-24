#ifndef PATHOS_WOLF
#define PATHOS_WOLF

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Wolf : public Hostile {
public:
  Wolf() : Hostile(100) {}
  ~Wolf() {}

  void beAttackedBy(Player &p);
};

} // namespace Pathos

#endif // PATHOS_WOLF
