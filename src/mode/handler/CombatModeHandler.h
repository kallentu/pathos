#ifndef PATHOS_COMBAT_MODE_HANDLER
#define PATHOS_COMBAT_MODE_HANDLER

#include "mode/handler/ModeHandler.h"
#include <memory>
#include <string>

namespace Pathos {

  class Char;

  class Event;

  class Hostile;

  class PathosInstance;

  class CombatModeHandler : public ModeHandler {
    Hostile *hostile;

    // Input from the user so far in the mode.
    std::string input;

    // Instance required to change player values and to check the combat manager.
    PathosInstance *inst;

  public:
    CombatModeHandler(Hostile *hostile, PathosInstance *inst);

    std::unique_ptr<Event> handle(const Char &c) override;

  private:
    std::unique_ptr<Event> parseEvent(int index);
  };

} // namespace Pathos

#endif // PATHOS_COMBAT_MODE_HANDLER
