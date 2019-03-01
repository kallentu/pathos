#ifndef PATHOS_PLAYER_MOVE_UP_EVENT
#define PATHOS_PLAYER_MOVE_UP_EVENT

#include "event/Event.h"

namespace Pathos {

class PathosInstance;

class PlayerMoveUpEvent : public Event {
public:
  PlayerMoveUpEvent() : Event() {}

  void begin(PathosInstance *inst) override;
};

} // namespace Pathos

#endif // PATHOS_PLAYER_MOVE_UP_EVENT
