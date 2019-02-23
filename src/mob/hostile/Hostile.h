#ifndef PATHOS_HOSTILE
#define PATHOS_HOSTILE

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

// Hostile mobs will attack the Player and other Friendly NPCs.
// Will attack them within range of 1 square.
class Hostile : MapObject, public Mob {
  size_t health;
  size_t damage;
  bool deceased;

public:
  Hostile(size_t health, size_t damage)
      : MapObject(MapObject::Char::Lantern), health{health}, damage{damage},
        deceased{false} {}

  size_t getHealth() const { return health; }
  void setHealth(size_t h) { health = h; }

  size_t getDamage() const { return damage; }
  void setDamage(size_t d) { damage = d; }

  bool isDeceased() const { return deceased; }
  void setDeceased(bool d) { deceased = d; }

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

  virtual void beAttackedBy(Player &p) = 0;
  virtual void beKilledBy(Player &p) = 0;
};

} // namespace Pathos

#endif // PATHOS_HOSTILE
