#ifndef PATHOS_COMBAT_MANAGER
#define PATHOS_COMBAT_MANAGER

#include <map>
#include <memory>
#include <vector>
#include <mob/hostile/Hostile.h>
#include "combat/CombatLog.h"

namespace Pathos {

  class CombatRequest;

  class PathosInstance;

  class CombatManager final {
    // Store hostile mob and the related combat logs until we leave combat mode.
    std::map<Hostile *, std::vector<std::unique_ptr<CombatLog>>> combatLogs;

  public:
    std::unique_ptr<CombatRequest> getCombatRequest(Hostile *hostile, PathosInstance *inst);

  private:
    // Certain statuses such as death take priority over whatever is currently in the combat log.
    // Return these combat requests immediately.
    std::unique_ptr<CombatRequest> getPriorityStatusRequest(PathosInstance *inst, Hostile *hostile);

    CombatLog *addLogForHostile(Hostile *hostile, CombatLog::Status status);

    static std::string getDescriptionWithStatus(CombatLog::Status status, Hostile *hostile);
  };
} // namespace Pathos

#endif //PATHOS_COMBAT_MANAGER
