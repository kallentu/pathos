#ifndef PATHOS_UPDATE_QUEST_EVENT
#define PATHOS_UPDATE_QUEST_EVENT

#include "event/Event.h"
#include "quest/Quest.h"

namespace Pathos {

class PathosInstance;

class UpdateQuestEvent : public Event {
  Quest *quest;

public:
  UpdateQuestEvent(Quest *quest) : Event(), quest{quest} {}

  void begin(PathosInstance *inst) override;
};

} // namespace Pathos

#endif // PATHOS_UPDATE_QUEST_EVENT
