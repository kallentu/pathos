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
#include <string>
#include <vector>

namespace Pathos {

class Player;
class Event;
class TalkRequest;

// Friendly mobs can interact with players.
// Can interact within range of 1 square
class Friendly : public  MapObject, public Mob {
public:
  Friendly(std::string name)
      : MapObject(MapObject::Char::Sterling), Mob(name, 500, 500, 500) {}

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

  // Must be overrided by concrete subclasses.
  virtual std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) = 0;
};

} // namespace Pathos

#endif // PATHOS_FRIENDLY
