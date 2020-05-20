#include "combat/CombatManager.h"
#include <core/PathosInstance.h>
#include <request/CombatRequest.h>
#include <mob/player/Player.h>

using namespace Pathos;

std::unique_ptr<CombatRequest> CombatManager::getCombatRequest(Hostile *hostile, PathosInstance *inst) {
  std::unique_ptr<CombatRequest> req = getPriorityStatusRequest(inst, hostile);
  if (req != nullptr) return req;

  // TODO: Otherwise, hostile gets to roll an attack always, and we show it to player as finished for them to take a move.
  // visitor pattern on hostile and the combat manager to auto allow the hostile to make a move based on percentages.


  // Check if hostile had previous combat log, otherwise initiate.
  if (combatLogs.count(hostile) == 0) {
    combatLogs[hostile] = std::vector<std::unique_ptr<CombatLog>>();
    combatLogs[hostile].push_back(std::make_unique<CombatLog>(CombatLog::Status::PlayerChooseAttack, "Choose your attack."));
  }

  return std::make_unique<CombatRequest>(hostile, inst->getPlayer(), combatLogs[hostile].back().get());
}

std::unique_ptr<CombatRequest> CombatManager::getPriorityStatusRequest(PathosInstance *inst, Hostile *hostile) {
  if (inst->getPlayer()->isDeceased()) {
    return std::make_unique<CombatRequest>(hostile, inst->getPlayer(), addLogForHostile(hostile, CombatLog::Status::PlayerDead));
  } else if (hostile->isDeceased()) {
    return std::make_unique<CombatRequest>(hostile, inst->getPlayer(), addLogForHostile(hostile, CombatLog::Status::HostileDead));
  }

  return nullptr;
}

CombatLog *CombatManager::addLogForHostile(Hostile *hostile, CombatLog::Status status) {
  combatLogs[hostile].push_back(std::make_unique<CombatLog>(status, getDescriptionWithStatus(status, hostile)));
  return combatLogs[hostile].back().get();
}

std::string CombatManager::getDescriptionWithStatus(CombatLog::Status status, Hostile *hostile) {
  // Keep in sync with [CombatLog::Status].
  if (status == CombatLog::Status::PlayerDead) {
    return "You are dead.";
  } else if (status == CombatLog::Status::HostileDead) {
    return hostile->getName() + " is dead.";
  } // TODO: attacking then when player attacks we have a playerattackhostile event that adds a combat log to the manager

  return "";
}