#include <event/MultipleEvent.h>
#include <event/UpdateQuestEvent.h>
#include "mode/handler/QuestModeHandler.h"
#include "controller/Char.h"
#include "event/LeaveModeEvent.h"
#include "request/QuestRequest.h"

using namespace Pathos;

QuestModeHandler::QuestModeHandler(PathosInstance *inst, QuestGiver *questGiver) : questGiver{questGiver} {
  // Initial work before first event, may change view as well.
  std::unique_ptr<QuestRequest> questReq = questGiver->retrieveQuestRequestWithInstance(inst);
  inst->notify(questReq.get());

  quest = questReq->getQuest();
}

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
        return std::make_unique<UpdateQuestEvent>(quest);
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
      if (c == 'a') {
        // Quest complete, show completed and leave.
        return std::make_unique<LeaveModeEvent>();
      }
      break;
    default:
      return std::make_unique<LeaveModeEvent>();
  }

  throw ParseError::NoEvent;
}
