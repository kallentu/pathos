#include "mode/handler/ModeHandler.h"
#include "controller/Input.h"
#include "event/Event.h"

using namespace Pathos;

std::unique_ptr<Event> ModeHandler::handle(std::unique_ptr<Input> input) {
  return input->beHandledBy(this);
}
