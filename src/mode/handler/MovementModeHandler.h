#ifndef PATHOS_MOVEMENT_MODE_HANDLER
#define PATHOS_MOVEMENT_MODE_HANDLER

#include "mode/handler/ModeHandler.h"
#include <memory>

namespace Pathos {

class Event;
class Char;

// Parses movement keys and space key.
class MovementModeHandler : public ModeHandler {
public:
  MovementModeHandler() {}

  std::unique_ptr<Event> handle(const Char &c) override;
};

} // namespace Pathos

#endif // PATHOS_MOVEMENT_MODE_HANDLER
