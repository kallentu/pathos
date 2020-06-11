#ifndef PATHOS_PLAYER
#define PATHOS_PLAYER

#include "item/Item.h"
#include "item/consume/Chicken.h"
#include "item/consume/SmallPotion.h"
#include "item/equip/bow/Bow.h"
#include "item/equip/greatsword/Greatsword.h"
#include "item/equip/staff/Staff.h"
#include "map/MapObject.h"
#include "mob/Mob.h"
#include "mob/friendly/Friendly.h"
#include "mob/friendly/merchant/Trader.h"
#include "mob/hostile/Hostile.h"
#include "request/TalkRequest.h"
#include <algorithm>
#include <cstddef>
#include <memory>
#include <string>
#include <vector>
#include <state/Level.h>

namespace Pathos {

class Event;

// The main player.
// Has customization options.
// Can speak to Friendly, attack Hostile, and romance Romanceable.
class Player final : MapObject, public Mob, public Trader {
  Level level;

public:
  Player()
      : MapObject(MapObject::Char::At), Mob("Periphas", 100, 5, 5), Trader() {}
  ~Player() override = default;

  // Level in numerical value.
  size_t getLevel() const { return level.getLevel(); }

  // The amount of experience at the current level, needed to level up.
  size_t getExperienceThreshold() const { return level.getExperienceThreshold(); }

  size_t getExperience() const { return level.getExperience(); }
  void addExperience(size_t ex) { level.addExperience(ex); }

  void attack(Hostile *h) { h->beAttackedBy(*this); }
  std::unique_ptr<TalkRequest> talkTo(Friendly *f) {
    return f->beTalkedToBy(*this);
  }

  void consume(Chicken &c) override { health += c.getHealthChange(); }
  void consume(SmallPotion &sp) override { health += sp.getHealthChange(); }

  void equip(Bow &b) override {
    magicDamage = b.getDamage() / 10;
    physicalDamage = b.getDamage() * 9 / 10;
  }
  void equip(Greatsword &gs) override { physicalDamage = gs.getDamage(); }
  void equip(Staff &s) override { magicDamage = s.getDamage(); }
};

} // namespace Pathos

#endif // PATHOS_PLAYER
