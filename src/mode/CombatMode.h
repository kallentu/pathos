#ifndef PATHOS_COMBAT_MODE
#define PATHOS_COMBAT_MODE

#include <mode/handler/CombatModeHandler.h>
#include "mode/Mode.h"

namespace Pathos {

  class Hostile;

  class CombatMode : public Mode {
    std::unique_ptr<CombatModeHandler> handler;

  public:
    CombatMode(PathosInstance *inst, Hostile *hostile);

    ModeHandler *getHandler() const override;
  };

} // namespace Pathos

#endif // PATHOS_COMBAT_MODE
