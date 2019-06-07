#include "quest/athens/KillWolvesQuest.h"
#include "core/PathosInstance.h"
#include "mob/friendly/quest/QuestGiver.h"
#include "quest/Quest.h"
#include "state/Stats.h"

using namespace Pathos;

KillWolvesQuest::KillWolvesQuest(QuestGiver *questGiver) : Quest(questGiver) {
  Quest::addDialogue(
      Quest::Status::NotStarted,
      "There's been a slight issue with the wolves around Athens.");
  Quest::addDialogue(Quest::Status::NotStarted,
                     "Try your hand at fighting 20 wolves. It would help "
                     "cull the population some.");
  Quest::addDialogue(Quest::Status::InProgress,
                     "Remember, we need 20 killed in total.");
  Quest::addDialogue(Quest::Status::Completed,
                     "Thank you. The citizens of Athens now feel safer.");
}

Quest::Status KillWolvesQuest::checkConditions(PathosInstance *inst) {
  switch (Quest::getStatus()) {
  case Quest::Status::NotStarted: {
    initialTotalKills = inst->getStats()->wolvesKilled;
    
    // TODO: Allow user to choose whether to progress quest.
    //Quest::setStatus(Quest::Status::InProgress);
    break;
  }
  case Quest::Status::InProgress: {
    int killed = inst->getStats()->wolvesKilled - initialTotalKills;
    if (killed >= 20)
      Quest::setStatus(Quest::Status::Completed);
    break;
  }
  case Quest::Status::Completed:
  default:
    break;
  }

  return Quest::getStatus();
}
