#ifndef PATHOS_ROMANCEABLE
#define PATHOS_ROMANCEABLE

#include "event/EventManager.h"
#include "mob/friendly/Friendly.h"
#include <memory>
#include <vector>

namespace Pathos {

class Player;
class Item;

// Romanceable NPCs that the Player can be in a relation with.
class Romanceable : virtual Friendly {
  size_t romanceExp;

public:
  Romanceable() : Friendly(), romanceExp{0} {}

  size_t getRomanceExp() const { return romanceExp; }
  void setRomanceExp(size_t exp) { romanceExp = exp; }
  void addRomanceExp(size_t expToAdd) { romanceExp += expToAdd; }
  void removeRomanceExp(size_t expToRemove) { romanceExp -= expToRemove; }

  void beMarriedBy(Player &p);
  void beGiftedBy(std::unique_ptr<Item> it, Player &p);

  // Increase romance points when talked to
  void beTalkedToBy(Player &p) override;

  // Subclass override for custom speech options.
  virtual void talkedToBy(Player &p) = 0;

  std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) override {
     return em->getEventList(*this);
  }
};

} // namespace Pathos

#endif // PATHOS_ROMANCEABLE
