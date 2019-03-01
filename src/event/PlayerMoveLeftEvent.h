#ifndef PATHOS_PLAYER_MOVE_LEFT_EVENT
#define PATHOS_PLAYER_MOVE_LEFT_EVENT

#include "event/Event.h"

namespace Pathos {

class PathosInstance;

class PlayerMoveLeftEvent : public Event {
public:
  PlayerMoveLeftEvent() : Event() {}

  void begin(PathosInstance *inst) override;
};

} // namespace Pathos

#endif // PATHOS_PLAYER_MOVE_LEFT_EVENT
