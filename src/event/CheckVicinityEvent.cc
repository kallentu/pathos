#include "event/CheckVicinityEvent.h"
#include <combat/CombatManager.h>
#include "core/PathosInstance.h"
#include "map/Map.h"
#include "mob/friendly/quest/QuestGiver.h"
#include "mode/QuestMode.h"
#include "quest/QuestManager.h"
#include "request/ClearEntireStatus.h"
#include "request/QuestRequest.h"
#include <memory>
#include <mode/CombatMode.h>
#include <request/CombatRequest.h>

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
    // View request based on status of the battle.
    // TODO remove this and put in init of CombatModeHandler
    // TODO then make the handler output more specific events
    // TODO these events change the logic + view when 'begin'
    std::unique_ptr<CombatRequest> combatReq = inst->getCombatManager()->getCombatRequest(hostile, inst);
    inst->notify(combatReq.get());

    // Input should be in attack mode.
    inst->runMode(std::make_unique<CombatMode>(inst, hostile));
  }

  // Check for quest givers.
  auto *questGiver =
      dynamic_cast<QuestGiver *>(map->get(actionPos->y, actionPos->x));
  if (questGiver != nullptr) {
    inst->runMode(std::make_unique<QuestMode>(inst, questGiver));
  }
}
