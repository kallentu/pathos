#ifndef PATHOS_UPDATE_QUEST_EVENT
#define PATHOS_UPDATE_QUEST_EVENT

#include "event/Event.h"

namespace Pathos {

class PathosInstance;
class Quest;

class UpdateQuestEvent : public Event {
  Quest *quest;

public:
  explicit UpdateQuestEvent(Quest *quest) : Event(), quest{quest} {}
  void begin(PathosInstance *inst) override;
};

} // namespace Pathos

#endif // PATHOS_UPDATE_QUEST_EVENT
