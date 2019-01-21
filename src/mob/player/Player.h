#ifndef PATHOS_PLAYER
#define PATHOS_PLAYER

#include "event/EventManager.h"
#include "item/consume/Chicken.h"
#include "item/consume/SmallPotion.h"
#include "item/interact/bow/Bow.h"
#include "item/interact/greatsword/Greatsword.h"
#include "item/interact/staff/Staff.h"
#include "map/MapObject.h"
#include "mob/Mob.h"
#include <cstddef>
#include <memory>
#include <string>
#include <vector>

namespace Pathos {

class Hostile;
class Event;

// The main player.
// Has customization options.
// Can interact with Friendly, attack Hostile, and romance Romanceable.
class Player final : MapObject, public Mob {
  std::string name;
  size_t health;
  size_t level;
  size_t experience;
  size_t damage;

public:
  Player() : MapObject(MapObject::Char::At) {}
  ~Player() {}

  size_t getHealth() const { return health; }
  void setHealth(size_t h) { health = h; }

  std::string getName() const { return name; }
  void setName(std::string n) { name = n; }

  size_t getLevel() const { return level; }
  void setLevel(size_t l) { level = l; }

  size_t getExperience() const { return experience; }
  void setExperience(size_t ex) { experience = ex; }

  size_t getDamage() const { return damage; }
  void setDamage(size_t d) { damage = d; }

  void attack(Hostile *h) { h->beAttackedBy(*this); }

  std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) override {
    return em->getEventList(*this);
  }

  void consume(Chicken &c) override { health += c.getHealthChange(); }
  void consume(SmallPotion &sp) override { health += sp.getHealthChange(); }

  void interactWith(Bow &b) override { damage += b.getDamage(); }
  void interactWith(Greatsword &gs) override { damage += gs.getDamage(); }
  void interactWith(Staff &s) override { damage += s.getDamage(); }
};

} // namespace Pathos

#endif // PATHOS_PLAYER
