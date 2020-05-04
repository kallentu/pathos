#ifndef PATHOS_COMBAT_REQUEST
#define PATHOS_COMBAT_REQUEST

#include <mob/hostile/Hostile.h>
#include "request/ViewRequest.h"

namespace Pathos {

  class View;

  struct CombatRequest : public ViewRequest {
    // Mob that the player is attacking.
    Hostile *hostile;

  public:
    enum class Status {
      PlayerChooseAttack,
      PlayerAttacked,
      HostileAttacked,
      HostileDead,
      PlayerDead
    };

    explicit CombatRequest(Hostile *hostile, CombatRequest::Status status) : hostile{hostile}, status{status} {}

    void beDrawnBy(View &view) const override;

    CombatRequest::Status getStatus() const { return status; }

    Hostile *getHostile() const { return hostile; }

  private:
    // State that the player currently needs to see in their view.
    CombatRequest::Status status;
  };
}

#endif // PATHOS_COMBAT_REQUEST
