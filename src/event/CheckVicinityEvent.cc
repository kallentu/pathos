#include "event/CheckVicinityEvent.h"
#include "core/PathosInstance.h"
#include "core/Position.h"
#include "event/Event.h"
#include "map/Map.h"
#include "mob/friendly/quest/QuestGiver.h"

using namespace Pathos;

CheckVicinityEvent::CheckVicinityEvent() : Event() {}

void CheckVicinityEvent::begin(PathosInstance *inst) {
  Map *map = inst->getMap();
  Position *actionPos = inst->getActionablePosition();

  if (dynamic_cast<QuestGiver *>(map->get(actionPos->y, actionPos->x))) {
    // TODO: QuestGivers should emit a TalkRequest as well as a
    // QuestStartRequest, QuestProgressRequest, if complete, no additional req
    // inst->notify(&req);
  }
}
