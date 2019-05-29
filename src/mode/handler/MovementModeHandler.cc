#include "mode/handler/MovementModeHandler.h"
#include "controller/Char.h"
#include "event/CheckVicinityEvent.h"
#include "event/Event.h"
#include "event/MultipleEvent.h"
#include "event/PlayerMoveDownEvent.h"
#include "event/PlayerMoveLeftEvent.h"
#include "event/PlayerMoveRightEvent.h"
#include "event/PlayerMoveUpEvent.h"
#include "event/QuitEvent.h"

using namespace Pathos;

std::unique_ptr<Event> MovementModeHandler::handle(const Char &c) {
  std::unique_ptr<MultipleEvent> events = std::make_unique<MultipleEvent>();

  switch (c.numValue()) {
  case Char::Arrow::Up:
    events->addEvent(std::make_unique<PlayerMoveUpEvent>());
    break;
  case Char::Arrow::Down:
    events->addEvent(std::make_unique<PlayerMoveDownEvent>());
    break;
  case Char::Arrow::Left:
    events->addEvent(std::make_unique<PlayerMoveLeftEvent>());
    break;
  case Char::Arrow::Right:
    events->addEvent(std::make_unique<PlayerMoveRightEvent>());
    break;
  case Char::Ctrl::C:
    return std::make_unique<QuitEvent>();
  }

  // Add event to check for interactables (NPC, hostiles) after movement.
  events->addEvent(std::unique_ptr<CheckVicinityEvent>());

  return events;
}
