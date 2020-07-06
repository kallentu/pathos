#include "combat/CombatManager.h"
#include <core/PathosInstance.h>
#include <request/CombatRequest.h>
#include <mob/player/Player.h>

using namespace Pathos;

CombatManager *CombatManager::_instance;

std::unique_ptr<CombatRequest> CombatManager::getCombatRequest(Hostile *hostile, PathosInstance *inst) {
  // Check if hostile had previous combat log, otherwise initiate.
  if (combatLogs.count(hostile) == 0) {
    combatLogs[hostile] = std::vector<std::unique_ptr<CombatLog>>();
  }

  // Priority requests that avoid any further attacks.
  if (inst->getPlayer()->isDeceased()) {
    return std::make_unique<CombatRequest>(hostile, inst->getPlayer(), addLogForHostile(hostile, CombatLog::Status::PlayerDead));
  } else if (hostile->isDeceased()) {
    return std::make_unique<CombatRequest>(hostile, inst->getPlayer(), addLogForHostile(hostile, CombatLog::Status::HostileDead));
  }

  return std::make_unique<CombatRequest>(hostile, inst->getPlayer(), addLogForHostile(hostile, CombatLog::Status::PlayerChooseAttack));
}

void CombatManager::addHostileAttackLog(Hostile *hostile, std::string description) {
  combatLogs[hostile].push_back(std::make_unique<CombatLog>(CombatLog::Status::HostileAttack, description));
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
  }

  return "Choose your attack.";
}