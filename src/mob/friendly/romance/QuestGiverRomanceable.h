#ifndef PATHOS_QUEST_GIVER_ROMANCEABLE
#define PATHOS_QUEST_GIVER_ROMANCEABLE

#include "mob/friendly/quest/QuestGiver.h"
#include "mob/friendly/romance/Romanceable.h"
#include <string>

namespace Pathos {

// Type of Friendly NPC that both can be romanced and give/take quests.
class QuestGiverRomanceable : public QuestGiver, public Romanceable {
public:
  explicit QuestGiverRomanceable(std::string name) : QuestGiver(), Romanceable(name) {}
};

} // namespace Pathos

#endif // PATHOS_QUEST_GIVER_ROMANCEABLE
