#ifndef PATHOS_INTERACTABLE
#define PATHOS_INTERACTABLE

#include "item/Item.h"

namespace Pathos {

class Mob;

// Items that can be interacted with.
// Example are weapons and levers.
class Interactable : public Item {
public:
  Interactable(size_t sellPrice, size_t buyPrice) : Item(sellPrice, buyPrice) {}

  virtual void beInteractedBy(Mob *m) { m->interactWith(*this); }
};

} // namespace Pathos

#endif // PATHOS_INTERACTABLE
