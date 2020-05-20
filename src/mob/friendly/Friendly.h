#ifndef PATHOS_FRIENDLY
#define PATHOS_FRIENDLY

#include "item/consume/Chicken.h"
#include "item/consume/SmallPotion.h"
#include "item/equip/bow/Bow.h"
#include "item/equip/greatsword/Greatsword.h"
#include "item/equip/staff/Staff.h"
#include "map/MapObject.h"
#include "mob/Mob.h"
#include <cstddef>
#include <memory>
#include <string>
#include <utility>

namespace Pathos {

class Player;
class Event;
class TalkRequest;

// Friendly mobs can interact with players.
// Can interact within range of 1 square
class Friendly : public  MapObject, public Mob {
public:
  explicit Friendly(std::string name)
      : MapObject(MapObject::Char::Sterling), Mob(std::move(name), 500, 500, 500) {}

  void consume(Chicken &c) override { health += c.getHealthChange(); }
  void consume(SmallPotion &sp) override {
    health += sp.getHealthChange();
  }

  void equip(Bow &b) override {
    magicDamage = b.getDamage() / 10;
    physicalDamage = b.getDamage() * 9 / 10;
  }
  void equip(Greatsword &gs) override {
    physicalDamage = gs.getDamage();
  }
  void equip(Staff &s) override { magicDamage = s.getDamage(); }

  // Must be overridden by concrete subclasses.
  virtual std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) = 0;
};

} // namespace Pathos

#endif // PATHOS_FRIENDLY
