#ifndef PATHOS_ROMANCEABLE
#define PATHOS_ROMANCEABLE

#include "mob/friendly/Friendly.h"
#include <memory>
#include <string>
#include <utility>

namespace Pathos {

class Player;
class Item;
class TalkRequest;

// Romanceable NPCs that the Player can be in a relation with.
class Romanceable : public Friendly {
  size_t romanceExp;

public:
  explicit Romanceable(std::string name) : Friendly(std::move(name)), romanceExp{0} {}

  size_t getRomanceExp() const { return romanceExp; }
  void setRomanceExp(size_t exp) { romanceExp = exp; }
  void addRomanceExp(size_t expToAdd) { romanceExp += expToAdd; }
  void removeRomanceExp(size_t expToRemove) { romanceExp -= expToRemove; }

  void beMarriedBy(Player &p);
  void beGiftedBy(std::unique_ptr<Item> it, Player &p);

  // Increase romance points when talked to
  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;

  // Subclass override for custom speech options.
  virtual std::unique_ptr<TalkRequest> talkedToBy(Player &p) = 0;
};

} // namespace Pathos

#endif // PATHOS_ROMANCEABLE
