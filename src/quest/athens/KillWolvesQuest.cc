#include "quest/athens/KillWolvesQuest.h"
#include "core/PathosInstance.h"
#include "mob/player/Player.h"
#include "state/Stats.h"

using namespace Pathos;

KillWolvesQuest::KillWolvesQuest(QuestGiver *questGiver) : Quest(questGiver) {
  Quest::setDialogue(
      Quest::Status::NotStarted,
      "There's been a slight issue with the wolves around Athens. Try your "
      "hand at fighting 20 wolves. It would help cull the population some.");
  Quest::setDialogue(Quest::Status::InProgress, "Remember, we need 20 killed in total.");
  Quest::setDialogue(Quest::Status::Completed,
                     "Thank you. The citizens of Athens now feel safer.");
}

Quest::Status KillWolvesQuest::checkConditions(PathosInstance *inst) {
  switch (Quest::getStatus()) {
    case Quest::Status::NotStarted: {
      initialTotalKills = inst->getStats()->wolvesKilled;
      Quest::setStatus(Quest::Status::InProgress);
      break;
    }
    case Quest::Status::InProgress: {
      int killed = inst->getStats()->wolvesKilled - initialTotalKills;
      Quest::setDialogue(Quest::Status::InProgress,
                         "Remember, you need to cull 20 of them. You have only killed " + std::to_string(killed) +
                         " wolves.");
      if (killed >= 20) {
        // Change status and give rewards.
        inst->getPlayer()->addExperience(1000);
        inst->getPlayer()->addDrachma(1000);
        Quest::setStatus(Quest::Status::Completed);
      }

      break;
    }
    case Quest::Status::Completed:
    default:
      break;
  }

  return Quest::getStatus();
}
