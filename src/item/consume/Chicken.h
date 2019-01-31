#ifndef PATHOS_CHICKEN
#define PATHOS_CHICKEN

#include "item/consume/Consumable.h"
#include "mob/Mob.h"

namespace Pathos {

// A small bird that can be consumed for health.
class Chicken : public Consumable {
public:
  // Restores 2000 health, sell for 500, buy for 1000.
  Chicken() : Consumable("chicken", 2000, 500, 1000) {}

  void beConsumedBy(Mob *m) { m->consume(*this); }
};

} // namespace Pathos

#endif // PATHOS_CHICKEN
