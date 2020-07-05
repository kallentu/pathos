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
#include <request/CombatRequest.h>
#include <combat/CombatManager.h>
#include <core/PathosInstance.h>
#include <combat/skill/Bite.h>

namespace Pathos {

// The main player.
// Has customization options.
// Can speak to Friendly, attack Hostile, and romance Romanceable.
  class Player final : MapObject, public Mob, public Trader {
    // Pointer to stats that can be changed according to what the player does.
    Stats *stats;

    Level level;

    // List of all possible skills, unlocked by the player.
    std::vector<std::unique_ptr<Skill>> allSkills;

    // List of active skills equipped by the player, max 4.
    std::vector<Skill *> activeSkills;

  public:
    explicit Player(Stats *stats)
        : MapObject(MapObject::Char::At), Mob("Periphas", 100, 5, 5), Trader(), stats{stats} {}

    ~Player() override = default;

    Stats *getStats() { return stats; }

    // Level in numerical value.
    size_t getLevel() const { return level.getLevel(); }

    // The amount of experience at the current level, needed to level up.
    size_t getExperienceThreshold() const { return level.getExperienceThreshold(); }

    size_t getExperience() const { return level.getExperience(); }

    void addExperience(size_t ex) { level.addExperience(ex); }

    // Attack hostile using skill number [skillIndex] in [activeSkills].
    std::unique_ptr<CombatRequest> attack(Hostile *h, PathosInstance *inst, int skillIndex) {
      // See [activeSkills]. Must have only 4 skills active at a time.
      if (skillIndex >= 4) return nullptr;

      // TODO: Change to actual skills by hostiles.
      Bite bite = Bite();

      // Attack the hostile, allow it to retaliate and get the request.
      h->beAttackedBy(*this, *inst->getCombatManager(), bite);
      
      inst->getCombatManager()->addHostileAttackLog(h, Bite().useSkillString(dynamic_cast<Mob *>(h), this));
      return inst->getCombatManager()->getCombatRequest(h, inst);
    }

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
