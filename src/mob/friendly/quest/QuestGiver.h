#ifndef PATHOS_QUEST_GIVER
#define PATHOS_QUEST_GIVER

#include "quest/Quest.h"
#include <memory>
#include <string>
#include <vector>

namespace Pathos {

class QuestManager;
class PathosInstance;
class QuestRequest;

// An NPC that gives a quest/is reported back to when quest finished.
// Quest logic is not processes here, but will be in the Quest itself.
// Subclasses will need an override on beTalkedToBy(Player &p).
class QuestGiver {
public:
  virtual std::unique_ptr<QuestRequest>
  haveQuestRequestRetrievedBy(QuestManager *qm, PathosInstance *inst) = 0;
};

} // namespace Pathos

#endif // PATHOS_QUEST_GIVER
