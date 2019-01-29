#ifndef PATHOS_PLAYER
#define PATHOS_PLAYER

#include "event/EventManager.h"
#include "item/Item.h"
#include "item/consume/Chicken.h"
#include "item/consume/SmallPotion.h"
#include "item/equip/bow/Bow.h"
#include "item/equip/greatsword/Greatsword.h"
#include "item/equip/staff/Staff.h"
#include "map/MapObject.h"
#include "mob/Mob.h"
#include "mob/hostile/Hostile.h"
#include <algorithm>
#include <cstddef>
#include <memory>
#include <string>
#include <vector>

namespace Pathos {

class Event;

// The main player.
// Has customization options.
// Can speak to Friendly, attack Hostile, and romance Romanceable.
class Player final : MapObject, public Mob {
  std::string name;
  size_t health;
  size_t level;
  size_t experience;
  size_t damage;
  size_t drachma;
  std::vector<std::unique_ptr<Item>> inventory;

public:
  Player() : MapObject(MapObject::Char::At) {}
  ~Player() {}

  // TODO: confirm this finder works.
  // May need to make custom finder
  bool hasItem(Item *it) {
    return std::find(inventory.begin(), inventory.end(), it) != inventory.end();
  }

  void addItemToInventory(std::unique_ptr<Item> it) {
    inventory.push_back(std::move(it));
  }

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

  size_t getDrachma() const { return drachma; }
  void setDrachma(size_t d) { drachma = d; }

  void attack(Hostile *h) { h->beAttackedBy(*this); }

  std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) override {
    return em->getEventList(*this);
  }

  void consume(Chicken &c) override { health += c.getHealthChange(); }
  void consume(SmallPotion &sp) override { health += sp.getHealthChange(); }

  void equip(Bow &b) override { damage += b.getDamage(); }
  void equip(Greatsword &gs) override { damage += gs.getDamage(); }
  void equip(Staff &s) override { damage += s.getDamage(); }
};

} // namespace Pathos

#endif // PATHOS_PLAYER
