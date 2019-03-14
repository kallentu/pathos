#ifndef PATHOS_QUEST_RECIPIENT
#define PATHOS_QUEST_RECIPIENT

#include "event/EventManager.h"
#include <memory>
#include <string>
#include <vector>

namespace Pathos {

// An NPC that is involved in a quest and progresses the quest forward.
class QuestRecipient {
public:
  std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) {
    return em->getEventList(*this);
  }
};

} // namespace Pathos

#endif // PATHOS_QUEST_RECIPIENT
