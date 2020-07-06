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
    static CombatManager *_instance;

    // Store hostile mob and the related combat logs until we leave combat mode.
    std::map<Hostile *, std::vector<std::unique_ptr<CombatLog>>> combatLogs;

    // Private constructor due to singleton.
    CombatManager() = default;

  public:
    static CombatManager *instance() {
      if (_instance == nullptr) _instance = new CombatManager();
      return _instance;
    }

    std::unique_ptr<CombatRequest> getCombatRequest(Hostile *hostile, PathosInstance *inst);

    void addHostileAttackLog(Hostile *hostile, std::string description);

    // Returns [true] if the last event in combat was the hostile attacking.
    bool hostileLastAttacked(Hostile *hostile) {
      if (combatLogs.count(hostile) == 0) {
        return false;
      }

      return combatLogs[hostile].back().get()->status == CombatLog::Status::HostileAttack;
    }

  private:
    CombatLog *addLogForHostile(Hostile *hostile, CombatLog::Status status);

    static std::string getDescriptionWithStatus(CombatLog::Status status, Hostile *hostile);
  };
} // namespace Pathos

#endif //PATHOS_COMBAT_MANAGER
