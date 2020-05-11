#ifndef PATHOS_COMBAT_LOG
#define PATHOS_COMBAT_LOG

#include <string>
#include <utility>

namespace Pathos {
  // Combat logs describe what's occurring in one moment of the battle.
  struct CombatLog {
    enum class Status {
      PlayerChooseAttack,
      HostileDead,
      PlayerDead
    };

    Status status;
    std::string description;

    CombatLog(Status status, std::string description) : status{status}, description{std::move(description)} {}
  };
} // namespace Pathos

#endif // PATHOS_COMBAT_LOG
