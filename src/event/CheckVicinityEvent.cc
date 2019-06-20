#include "event/CheckVicinityEvent.h"
#include "core/PathosInstance.h"
#include "core/Position.h"
#include "event/Event.h"
#include "map/Map.h"
#include "mob/friendly/quest/QuestGiver.h"
#include "mode/QuestMode.h"
#include "quest/QuestManager.h"
#include "request/ClearQuickStatusRequest.h"
#include "request/ClearTalkRequest.h"
#include "request/QuestRequest.h"
#include <memory>

using namespace Pathos;

CheckVicinityEvent::CheckVicinityEvent() : Event() {}

void CheckVicinityEvent::begin(PathosInstance *inst) {
  Map *map = inst->getMap();
  Position *actionPos = inst->getActionablePosition();

  // Clear prior NPC dialogue since we moved.
  std::unique_ptr<ClearTalkRequest> clearTalkReq =
      std::make_unique<ClearTalkRequest>();
  inst->notify(clearTalkReq.get());

  // Clear the line for future usage or just makes sense
  // when player walks away.
  std::unique_ptr<ClearQuickStatusRequest> clearStatusReq =
      std::make_unique<ClearQuickStatusRequest>();
  inst->notify(clearStatusReq.get());

  QuestGiver *questGiver =
      dynamic_cast<QuestGiver *>(map->get(actionPos->y, actionPos->x));
  if (questGiver != nullptr) {
    std::unique_ptr<QuestRequest> questReq =
        questGiver->haveQuestRequestRetrievedBy(inst->getQuestManager(), inst);
    inst->notify(questReq.get());

    // If not already in quest mode, go into it.
    if (!dynamic_cast<const QuestMode *>(inst->getActiveMode())) {
      inst->runMode(std::make_unique<QuestMode>(inst, questReq->getQuest()));
    }
  }
}
