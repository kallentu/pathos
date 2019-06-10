#include "quest/QuestManager.h"
#include "mob/friendly/quest/Ariadne.h"
#include "mob/friendly/quest/Gaia.h"
#include "mob/friendly/quest/QuestGiver.h"
#include "quest/Quest.h"
#include "quest/athens/KillWolvesQuest.h"
#include "request/QuestRequest.h"
#include <map>
#include <memory>
#include <string>

using namespace Pathos;

std::unique_ptr<QuestRequest>
QuestManager::getQuestRequest(Gaia &gaia, PathosInstance *inst) {
  // Check if quest exists, otherwise initiate.
  if (quests.count("killwolvesquest") == 0) {
    quests["killwolvesquest"] = std::make_unique<KillWolvesQuest>(&gaia);
  }

  // Check conditions of quest, return quest request accordingly.
  Quest *kwq = quests["killwolvesquest"].get();
  Quest::Status status = kwq->getStatus();

  return getRequestFromStatus(status, kwq, inst);
}

// TODO: Ariadne's quest
std::unique_ptr<QuestRequest>
QuestManager::getQuestRequest(Ariadne &ariadne, PathosInstance *inst) {
  return nullptr;
}

std::unique_ptr<QuestRequest>
QuestManager::getRequestFromStatus(Quest::Status status, Quest *quest,
                                   PathosInstance *inst) {
  // Make sure we are updated with correct status.
  Quest::Status currentStatus = status;
  if (status == Quest::Status::InProgress) {
    currentStatus = quest->updateQuestStatus(inst);
  }

  return std::make_unique<QuestRequest>(currentStatus, quest);
}
