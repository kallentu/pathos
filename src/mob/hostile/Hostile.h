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
#include <string>
#include <vector>

namespace Pathos {

class Player;
class Event;

// Hostile mobs will attack the Player and other Friendly NPCs.
// Will attack them within range of 1 square.
class Hostile : MapObject, public Mob {
public:
  Hostile(std::string name, size_t health, size_t magicDamage,
          size_t physicalDamage)
      : MapObject(MapObject::Char::Lantern),
        Mob(name, health, magicDamage, physicalDamage) {}

  virtual std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) override {
    return em->getEventList(*this);
  }

  virtual void consume(Chicken &c) override { health += c.getHealthChange(); }
  virtual void consume(SmallPotion &sp) override {
    health += sp.getHealthChange();
  }

  virtual void equip(Bow &b) override {
    magicDamage = b.getDamage() / 10;
    physicalDamage = b.getDamage() * 9 / 10;
  }
  virtual void equip(Greatsword &gs) override {
    physicalDamage = gs.getDamage();
  }
  virtual void equip(Staff &s) override { magicDamage = s.getDamage(); }

  virtual void beAttackedBy(Player &p) = 0;
  virtual void beKilledBy(Player &p) = 0;
};

} // namespace Pathos

#endif // PATHOS_HOSTILE
