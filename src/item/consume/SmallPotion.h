#ifndef PATHOS_SMALL_POTION
#define PATHOS_SMALL_POTION

#include "item/consume/Consumable.h"

namespace Pathos {

class Mob;

// A weak potion consumed for health.
class SmallPotion : public Consumable {
public:
  // Restores 200 health, sell for 50, buy for 100.
  SmallPotion() : Consumable(200, 50, 100) {}

  void beConsumedBy(Mob *m) { m->consume(*this); }
};

} // namespace Pathos

#endif // PATHOS_SMALL_POTION
