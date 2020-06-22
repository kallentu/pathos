#include "mode/handler/CombatModeHandler.h"
#include <event/LeaveModeEvent.h>
#include <request/CombatRequest.h>
#include <event/PlayerAttackHostileEvent.h>
#include <event/MultipleEvent.h>
#include <event/MobKilledEvent.h>
#include "controller/Char.h"

using namespace Pathos;

Pathos::CombatModeHandler::CombatModeHandler(Hostile *hostile, PathosInstance *inst) : hostile{hostile}, inst{inst} {
  std::unique_ptr<CombatRequest> combatReq = inst->getCombatManager()->getCombatRequest(hostile, inst);
  inst->notify(combatReq.get());
}

std::unique_ptr<Event> Pathos::CombatModeHandler::handle(const Pathos::Char &c) {
  // Add character to currently parsed string
  // Would be at different states.
  input.push_back(c.charValue());

  try {
    std::unique_ptr<Event> event = parseEvent(0);
    input.clear();
    return event;
  } catch (ParseError e) {
    // Bad input, won't do anything and remove the error char.
    input.pop_back();
    return nullptr;
  }
}

std::unique_ptr<Event> Pathos::CombatModeHandler::parseEvent(int index) {
  // Parses at particular index in case we are not always grabbing the most immediate value.
  // ie. previous choices of input matter.
  char c = input[index];

  // Hostile death exits combat, removes the hostile from the map.
  if (hostile->isDeceased()) {
    std::unique_ptr<MultipleEvent> events = std::make_unique<MultipleEvent>();
    events->addEvent(std::make_unique<MobKilledEvent>());
    events->addEvent(std::make_unique<LeaveModeEvent>());
    return events;
  }

  // We are always attacking. Hostile will attack on its own, no prompt needed.
  switch (c) {
    case '1':
      return std::make_unique<PlayerAttackHostileEvent>(hostile, 1);
    case '2':
      return std::make_unique<PlayerAttackHostileEvent>(hostile, 2);
    case '3':
      return std::make_unique<PlayerAttackHostileEvent>(hostile, 3);
    case '4':
      return std::make_unique<PlayerAttackHostileEvent>(hostile, 4);
    case 'r':
      // (r) for run away.
      return std::make_unique<LeaveModeEvent>();
  }

  throw ParseError::NoEvent;
}
