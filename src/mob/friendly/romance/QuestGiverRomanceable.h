#ifndef PATHOS_QUEST_GIVER_ROMANCEABLE
#define PATHOS_QUEST_GIVER_ROMANCEABLE

#include "event/EventManager.h"
#include "mob/friendly/quest/QuestGiver.h"
#include "mob/friendly/romance/Romanceable.h"
#include <iterator>
#include <memory>
#include <vector>

namespace Pathos {

// Type of Friendly NPC that both can be romanced and give/take quests.
class QuestGiverRomanceable : public QuestGiver, public Romanceable {
public:
  QuestGiverRomanceable() : QuestGiver(), Romanceable() {}

  // Combines the two event lists
  std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) override {
    std::vector<std::unique_ptr<Event>> questGiverEvents =
        QuestGiver::callEventManagerForEventList(em);
    std::vector<std::unique_ptr<Event>> romanceEvents =
        Romanceable::callEventManagerForEventList(em);

    std::vector<std::unique_ptr<Event>> combinedEvents;
    combinedEvents.reserve(questGiverEvents.size() + romanceEvents.size());
    std::move(questGiverEvents.begin(), questGiverEvents.end(),
              std::back_inserter(combinedEvents));
    std::move(romanceEvents.begin(), romanceEvents.end(),
              std::back_inserter(combinedEvents));
    return combinedEvents;
  }
};

} // namespace Pathos

#endif // PATHOS_QUEST_GIVER_ROMANCEABLE
