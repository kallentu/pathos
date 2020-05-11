#ifndef PATHOS_COMBAT_MODE_HANDLER
#define PATHOS_COMBAT_MODE_HANDLER

#include <mob/hostile/Hostile.h>
#include "mode/handler/ModeHandler.h"
#include <memory>
#include <string>

namespace Pathos {

  class Event;

  class Char;

  class CombatModeHandler : public ModeHandler {
    Hostile *hostile;
    Player *player;
    std::string input;

  public:
    explicit CombatModeHandler(Hostile *hostile, Player *player) : hostile{hostile}, player{player} {}

    std::unique_ptr<Event> handle(const Char &c) override;

  private:
    std::unique_ptr<Event> parseEvent(int index);
  };

} // namespace Pathos

#endif // PATHOS_COMBAT_MODE_HANDLER
