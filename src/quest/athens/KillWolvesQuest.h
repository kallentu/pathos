#ifndef PATHOS_KILL_WOLVES_QUEST
#define PATHOS_KILL_WOLVES_QUEST

namespace Pathos {

#include "core/PathosInstance.h"
#include "mob/friendly/quest/QuestGiver.h"
#include "quest/Quest.h"

// Kill 20 wolves in Athens (Level 1)
class KillWolvesQuest : public Quest {

  // Quest complete once currentTotalKills - initialTotalKills.
  int initialTotalKills;

public:
  KillWolvesQuest(QuestGiver *questGiver) : Quest(questGiver) {
    Quest::addDialogue(
        Quest::Status::NotStarted,
        "There's been a slight issue with the wolves around town.");
    Quest::addDialogue(Quest::Status::NotStarted,
                       "Think you can help kill 20 wolves for us? It would "
                       "help cull the population some.");
    Quest::addDialogue(Quest::Status::InProgress,
                       "Remember, we need 20 killed in total.");
    Quest::addDialogue(
        Quest::Status::Completed,
        "Thank you so much! Now the town's kids can go out and play.");
  }

  Quest::Status checkConditions(PathosInstance *inst) override {
    switch (Quest::getStatus()) {
    case Quest::Status::NotStarted:
      // TODO:
      // if (user clicked yes)
      // player->getStats().wolvesKilled;
      break;
    case Quest::Status::InProgress:
      int wolvesKilled = inst->stats->wolvesKilled - initialTotalKills;
      if (wolvesKilled >= 20)
        Quest::setStatus(Quest::Status::Completed);
      break;
    case Quest::Status::Completed:
    default:
      break;
    }

    return Quest::getStatus();
  }
};

} // namespace Pathos

#endif
