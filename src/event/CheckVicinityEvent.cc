#include "event/CheckVicinityEvent.h"
#include "core/PathosInstance.h"
#include "map/Map.h"
#include "mob/friendly/quest/QuestGiver.h"
#include "mob/hostile/Hostile.h"
#include "mode/QuestMode.h"
#include "request/ClearEntireStatus.h"
#include "request/QuestRequest.h"
#include <memory>
#include <mode/CombatMode.h>

using namespace Pathos;

CheckVicinityEvent::CheckVicinityEvent() : Event() {}

void CheckVicinityEvent::begin(PathosInstance *inst) {
  Map *map = inst->getMap();
  Position *actionPos = inst->getActionablePosition();

  // Clear prior main and quick status since we moved.
  std::unique_ptr<ClearEntireStatus> clearReq =
      std::make_unique<ClearEntireStatus>();
  inst->notify(clearReq.get());

  // Check for hostile mobs before any other mob.
  auto *hostile = dynamic_cast<Hostile *>(map->get(actionPos->y, actionPos->x));
  if (hostile != nullptr) {
    inst->runMode(std::make_unique<CombatMode>(inst, hostile));
  }

  // Check for quest givers.
  auto *questGiver =
      dynamic_cast<QuestGiver *>(map->get(actionPos->y, actionPos->x));
  if (questGiver != nullptr) {
    inst->runMode(std::make_unique<QuestMode>(inst, questGiver));
  }
}
