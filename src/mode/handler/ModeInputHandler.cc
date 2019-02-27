#include "mode/handler/ModeInputHandler.h"
#include "controller/Input.h"
#include "event/Event.h"

using namespace Pathos;

std::unique_ptr<Event> ModeInputHandler::handle(std::unique_ptr<Input> input) {
  return input->beHandledBy(this);
}
