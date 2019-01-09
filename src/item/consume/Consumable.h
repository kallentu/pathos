#ifndef PATHOS_CONSUMABLE
#define PATHOS_CONSUMABLE

#include "item/Item.h"

namespace Pathos {

class Mob;

// Items that can be consumed.
// Examples are food items like Chicken or Apple.
class Consumable : public Item {

  // Positive values are health gain, negative values are health loss.
  size_t healthChange;

public:
  Consumable(size_t healthChange, size_t sellPrice, size_t buyPrice)
      : Item(sellPrice, buyPrice), healthChange{healthChange} {}

  size_t getHealthChange() const { return healthChange; }
  void setHealthChange(size_t h) { healthChange = h; }

  virtual void beConsumedBy(Mob *m) = 0;
};

} // namespace Pathos

#endif // PATHOS_CONSUMABLE
