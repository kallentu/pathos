#ifndef PATHOS_FRIENDLY
#define PATHOS_FRIENDLY

#include "event/EventManager.h"
#include "item/consume/Chicken.h"
#include "item/consume/SmallPotion.h"
#include "item/equip/bow/Bow.h"
#include "item/equip/greatsword/Greatsword.h"
#include "item/equip/staff/Staff.h"
#include "map/MapObject.h"
#include "mob/Mob.h"
#include <cstddef>
#include <memory>
#include <vector>

namespace Pathos {

class Player;
class Event;

// Friendly mobs can interact with players.
// Can interact within range of 1 square
class Friendly : MapObject, public Mob {
  size_t health;
  size_t damage;

public:
  Friendly()
      : MapObject(MapObject::Char::Sterling), Mob(), health{500}, damage{500} {}

  size_t getHealth() const { return health; }
  void setHealth(size_t h) { health = h; }

  size_t getDamage() const { return damage; }
  void setDamage(size_t d) { damage = d; }

  virtual std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) override {
    return em->getEventList(*this);
  }

  virtual void consume(Chicken &c) override { health += c.getHealthChange(); }
  virtual void consume(SmallPotion &sp) override {
    health += sp.getHealthChange();
  }

  virtual void equip(Bow &b) override { damage += b.getDamage(); }
  virtual void equip(Greatsword &gs) override { damage += gs.getDamage(); }
  virtual void equip(Staff &s) override { damage += s.getDamage(); }

  virtual void beTalkedToBy(Player &p) = 0;
};

} // namespace Pathos

#endif // PATHOS_FRIENDLY
