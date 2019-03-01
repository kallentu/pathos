#ifndef PATHOS_PLAYER_MOVE_RIGHT_EVENT
#define PATHOS_PLAYER_MOVE_RIGHT_EVENT

#include "event/Event.h"

namespace Pathos {

class PathosInstance;

class PlayerMoveRightEvent : public Event {
public:
  PlayerMoveRightEvent() : Event() {}

  void begin(PathosInstance *inst) override;
};

} // namespace Pathos

#endif // PATHOS_PLAYER_MOVE_RIGHT_EVENT
