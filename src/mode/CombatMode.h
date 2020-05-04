#ifndef PATHOS_COMBAT_MODE
#define PATHOS_COMBAT_MODE

#include <mode/handler/CombatModeHandler.h>
#include "mode/Mode.h"
#include "mob/hostile/Hostile.h"

namespace Pathos {

  class CombatMode : public Mode {
    Hostile *hostile;
    std::unique_ptr<CombatModeHandler> handler;

  public:
    CombatMode(PathosInstance *inst, Hostile *hostile);

    ModeHandler *getHandler() const override;
    Hostile *getHostile() { return hostile; }
  };

} // namespace Pathos

#endif // PATHOS_COMBAT_MODE
