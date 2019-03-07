#include "mode/handler/MovementModeHandler.h"
#include "controller/Char.h"
#include "event/Event.h"
#include "event/PlayerMoveDownEvent.h"
#include "event/PlayerMoveLeftEvent.h"
#include "event/PlayerMoveRightEvent.h"
#include "event/PlayerMoveUpEvent.h"
#include "event/QuitEvent.h"

using namespace Pathos;

std::unique_ptr<Event> MovementModeHandler::handle(const Char &c) {
  std::unique_ptr<Event> event;

  switch (c.numValue()) {
  case Char::Arrow::Up:
    event = std::make_unique<PlayerMoveUpEvent>();
    break;
  case Char::Arrow::Down:
    event = std::make_unique<PlayerMoveDownEvent>();
    break;
  case Char::Arrow::Left:
    event = std::make_unique<PlayerMoveLeftEvent>();
    break;
  case Char::Arrow::Right:
    event = std::make_unique<PlayerMoveRightEvent>();
    break;
  case Char::Ctrl::C:
    event = std::make_unique<QuitEvent>();
    break;
  }

  return event;
}
