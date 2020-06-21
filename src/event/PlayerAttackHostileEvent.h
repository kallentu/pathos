#ifndef PATHOS_PLAYER_ATTACK_HOSTILE_EVENT
#define PATHOS_PLAYER_ATTACK_HOSTILE_EVENT

#include <cstdio>
#include <request/MultipleRequest.h>
#include <core/PathosInstance.h>
#include <mob/player/Player.h>
#include "event/Event.h"

namespace Pathos {

class PlayerAttackHostileEvent : public Event {
  Hostile *hostile;
  size_t skillIndex;

public:
  explicit PlayerAttackHostileEvent(Hostile *hostile, size_t skillIndex) : Event(), hostile{hostile}, skillIndex{skillIndex} {}

  void begin(PathosInstance *inst) override {
    // Clear prior main and quick status.
    // Attack based on the skill we chose.
    std::unique_ptr<MultipleRequest> request = std::make_unique<MultipleRequest>();
    request->addRequest(std::make_unique<ClearEntireStatus>());
    request->addRequest(inst->getPlayer()->attack(hostile, inst, skillIndex));
    inst->notify(request.get());
  }
};

} // namespace Pathos

#endif // PATHOS_PLAYER_ATTACK_HOSTILE_EVENT
