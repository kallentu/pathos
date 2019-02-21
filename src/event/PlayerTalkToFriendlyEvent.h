#ifndef PATHOS_PLAYER_TALK_TO_FRIENDLY_EVENT
#define PATHOS_PLAYER_TALK_TO_FRIENDLY_EVENT

#include "event/Event.h"
#include "mob/friendly/Friendly.h"

namespace Pathos {

class PathosInstance;

class PlayerTalkToFriendlyEvent : public Event {
  Friendly *friendly;

public:
  PlayerTalkToFriendlyEvent(Friendly *friendly) : Event(), friendly{friendly} {}

  void begin(PathosInstance *inst) override;
};

} // namespace Pathos

#endif // PATHOS_PLAYER_TALK_TO_FRIENDLY_EVENT
