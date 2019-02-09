#ifndef PATHOS_QUEST_GIVER
#define PATHOS_QUEST_GIVER

#include "event/EventManager.h"
#include "mob/friendly/Friendly.h"
#include <memory>
#include <vector>

namespace Pathos {

// An NPC that gives a quest/is reported back to when quest finished.
// Quest logic is not processes here, but will be in the Quest itself.
// Subclasses will need an override on beTalkedToBy(Player &p).
class QuestGiver : virtual Friendly {
public:
  QuestGiver() : Friendly() {}

  std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) override {
    return em->getEventList(*this);
  }
};

} // namespace Pathos

#endif // PATHOS_QUEST_GIVER
