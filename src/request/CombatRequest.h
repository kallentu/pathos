#ifndef PATHOS_COMBAT_REQUEST
#define PATHOS_COMBAT_REQUEST

#include <mob/hostile/Hostile.h>
#include <combat/CombatLog.h>
#include "request/ViewRequest.h"

namespace Pathos {

  class View;

  struct CombatRequest : public ViewRequest {
    // Mob that the player is attacking. Values in these mobs used for view changes.
    Hostile *hostile;
    Player *player;

    // State that the player currently needs to see in their view.
    CombatLog *log;

  public:
    explicit CombatRequest(Hostile *hostile, Player *player, CombatLog *log) : hostile{hostile}, player{player}, log{log} {}

    void beDrawnBy(View &view) const override;
  };
}

#endif // PATHOS_COMBAT_REQUEST
