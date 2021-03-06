#ifndef PATHOS_HOSTILE
#define PATHOS_HOSTILE

#include "item/consume/Chicken.h"
#include "item/consume/SmallPotion.h"
#include "item/equip/bow/Bow.h"
#include "item/equip/greatsword/Greatsword.h"
#include "item/equip/staff/Staff.h"
#include "map/MapObject.h"
#include "mob/Mob.h"
#include <cstddef>
#include <string>
#include <utility>

namespace Pathos {

  class CombatManager;

  class Event;

  class Player;

  class Skill;

  // Hostile mobs will attack the Player and other Friendly NPCs.
  // Will attack them within range of 1 square.
  class Hostile : public MapObject, public Mob {
  public:
    Hostile(std::string name, size_t health, size_t magicDamage,
            size_t physicalDamage)
        : MapObject(MapObject::Char::Lantern),
          Mob(std::move(name), health, magicDamage, physicalDamage) {}

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

    void beAttackedBy(Player &p, Skill &s);

  private:
    // TODO: Override this method to attack back or use special attack abilities, but should make completely virtual.
    // Adds to logs for CombatManager.
    virtual void retaliate(Player &p) { (void)p; }

    // Override method to set the amount of experience and rewards gained (loot).
    virtual void beKilledBy(Player &p) = 0;
  };

} // namespace Pathos

#endif // PATHOS_HOSTILE
