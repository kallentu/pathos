#ifndef PATHOS_KILL_WOLVES_QUEST
#define PATHOS_KILL_WOLVES_QUEST

#include "quest/Quest.h"

namespace Pathos {

class QuestGiver;
class PathosInstance;

// Kill 20 wolves in Athens (Level 1)
class KillWolvesQuest : public Quest {

  // Quest complete once currentTotalKills - initialTotalKills.
  int initialTotalKills;

public:
  KillWolvesQuest(QuestGiver *questGiver);
  Quest::Status checkConditions(PathosInstance *inst) override;
};

} // namespace Pathos

#endif
