#ifndef PATHOS_PLAYER_ATTACK_HOSTILE_EVENT
#define PATHOS_PLAYER_ATTACK_HOSTILE_EVENT

namespace Pathos {

class PathosInstance;

class PlayerAttackHostileEvent : public Event {
public:
  PlayerAttackHostileEvent() {}

  // TODO: Once Player is added to PathosInstance, complete this.
  void begin(PathosInstance *inst) override {} //{ p->attack(h); }
};

} // namespace Pathos

#endif // PATHOS_PLAYER_ATTACK_HOSTILE_EVENT
