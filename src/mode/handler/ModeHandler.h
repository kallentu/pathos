#ifndef PATHOS_MODE_HANDLER
#define PATHOS_MODE_HANDLER

#include <memory>

namespace Pathos {

  class Input;

  class Event;

  class Char;

  class ModeHandler {
  public:
    ModeHandler() = default;

    virtual ~ModeHandler() = default;

    std::unique_ptr<Event> handle(std::unique_ptr<Input> input);

    // Handles Char input and returns appropriate events to process.
    virtual std::unique_ptr<Event> handle(const Char &c) = 0;

  protected:
    enum class ParseError {
      NoEvent
    };
  };

} // namespace Pathos

#endif // PATHOS_MODE_HANDLER
