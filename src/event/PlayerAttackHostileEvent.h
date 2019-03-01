#ifndef PATHOS_PLAYER_ATTACK_HOSTILE_EVENT
#define PATHOS_PLAYER_ATTACK_HOSTILE_EVENT

#include "event/Event.h"

namespace Pathos {

class PathosInstance;

class PlayerAttackHostileEvent : public Event {
public:
  PlayerAttackHostileEvent() : Event() {}

  // TODO: Once Player is added to PathosInstance, complete this.
  void begin(PathosInstance *inst) override {} //{ p->attack(h); }
};

} // namespace Pathos

#endif // PATHOS_PLAYER_ATTACK_HOSTILE_EVENT
