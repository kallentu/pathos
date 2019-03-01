#ifndef PATHOS_PLAYER_MOVE_DOWN_EVENT
#define PATHOS_PLAYER_MOVE_DOWN_EVENT

#include "event/Event.h"

namespace Pathos {

class PathosInstance;

class PlayerMoveDownEvent : public Event {
public:
  PlayerMoveDownEvent() : Event() {}

  void begin(PathosInstance *inst) override;
};

} // namespace Pathos

#endif // PATHOS_PLAYER_MOVE_DOWN_EVENT
