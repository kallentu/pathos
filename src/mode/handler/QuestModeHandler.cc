#include <event/MultipleEvent.h>
#include <event/UpdateQuestEvent.h>
#include "mode/handler/QuestModeHandler.h"
#include "controller/Char.h"
#include "event/CheckVicinityEvent.h"
#include "event/Event.h"
#include "event/LeaveModeEvent.h"
#include "quest/Quest.h"

using namespace Pathos;

enum class ParseError { NoEvent };

std::unique_ptr<Event> QuestModeHandler::handle(const Char &c) {
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

std::unique_ptr<Event> QuestModeHandler::parseEvent(int index) {
  char c = input[index];

  switch (quest->getStatus()) {
  case Quest::Status::NotStarted:
    if (c == 'a') {
      // Accept quest
      std::unique_ptr<MultipleEvent> multipleEvent = std::make_unique<MultipleEvent>();
      multipleEvent->addEvent(std::make_unique<UpdateQuestEvent>(quest));
      multipleEvent->addEvent(std::make_unique<CheckVicinityEvent>());
      return multipleEvent;
    } else if (c == 'd') {
      // Don't actually decline, but just quit the dialogue since there's
      // nothing more to say.
      return std::make_unique<LeaveModeEvent>();
    }
    break;
  case Quest::Status::InProgress:
    if (c == 'a') {
      // Nothing more to interact with, once quest done then come back.
      return std::make_unique<LeaveModeEvent>();
    }
    break;
  case Quest::Status::Completed:
    return std::make_unique<LeaveModeEvent>();
  default:
    break;
  }

  throw ParseError::NoEvent;
}
