#ifndef PATHOS_ATTACK_MODE
#define PATHOS_ATTACK_MODE

#include <mode/handler/AttackModeHandler.h>
#include "mode/Mode.h"
#include "mob/hostile/Hostile.h"

namespace Pathos {

  class AttackMode : public Mode {
    Hostile *hostile;
    std::unique_ptr<AttackModeHandler> handler;

  public:
    AttackMode(PathosInstance *inst, Hostile *hostile);

    ModeHandler *getHandler() const override;
    Hostile *getHostile() { return hostile; }
  };

} // namespace Pathos

#endif // PATHOS_ATTACK_MODE
