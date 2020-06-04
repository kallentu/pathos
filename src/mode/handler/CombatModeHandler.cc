#include "mode/handler/CombatModeHandler.h"
#include <event/LeaveModeEvent.h>
#include <request/CombatRequest.h>
#include "combat/CombatManager.h"
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

  if (c == 'a') {
    // TODO (a) for basic attack.
  } else if (c == 's') {
    // TODO (s) for basic attack 2.
  } else if (c == 'd') {
    // TODO (d) for basic attack 3.
  } else if (c == 'c') {
    // (c) for run away.
    return std::make_unique<LeaveModeEvent>();
  }

  throw ParseError::NoEvent;
}
