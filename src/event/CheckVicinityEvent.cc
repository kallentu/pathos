#include "event/CheckVicinityEvent.h"
#include "core/PathosInstance.h"
#include "core/Position.h"
#include "event/Event.h"
#include "map/Map.h"
#include "mob/friendly/quest/QuestGiver.h"
#include "quest/QuestManager.h"
#include "request/QuestRequest.h"
#include <memory>

using namespace Pathos;

CheckVicinityEvent::CheckVicinityEvent() : Event() {}

void CheckVicinityEvent::begin(PathosInstance *inst) {
  Map *map = inst->getMap();
  Position *actionPos = inst->getActionablePosition();

  QuestGiver *questGiver =
      dynamic_cast<QuestGiver *>(map->get(actionPos->y, actionPos->x));
  if (questGiver != nullptr) {
    std::unique_ptr<QuestRequest> req =
        questGiver->haveQuestRequestRetrievedBy(inst->getQuestManager(), inst);
    inst->notify(&req);

    // TODO: go into quest mode so they can select accept/decline or exit based
    // on quest status
  }
}
