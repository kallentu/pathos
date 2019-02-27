#ifndef PATHOS_MODE_INPUT_HANDLER
#define PATHOS_MODE_INPUT_HANDLER

#include <memory>

namespace Pathos {

class Input;
class Event;
class Char;

class ModeInputHandler {
public:
  ModeInputHandler() {}
  virtual ~ModeInputHandler() {}

  std::unique_ptr<Event> handle(std::unique_ptr<Input> input);

  // Handles Char input and returns appropriate events to process.
  virtual std::unique_ptr<Event> handle(const Char &c) = 0;
};

} // namespace Pathos

#endif // PATHOS_MODE_INPUT_HANDLER
