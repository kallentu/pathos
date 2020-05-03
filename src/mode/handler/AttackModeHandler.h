#ifndef PATHOS_ATTACK_MODE_HANDLER
#define PATHOS_ATTACK_MODE_HANDLER

#include <mob/hostile/Hostile.h>
#include "mode/handler/ModeHandler.h"
#include <memory>
#include <string>

namespace Pathos {

  class Event;

  class Char;

  class AttackModeHandler : public ModeHandler {
    Hostile *hostile;
    std::string input;
  public:
    explicit AttackModeHandler(Hostile *hostile) : hostile{hostile} {}

    std::unique_ptr<Event> handle(const Char &c) override;

  private:
    std::unique_ptr<Event> parseEvent(int index);
  };

} // namespace Pathos

#endif // PATHOS_ATTACK_MODE_HANDLER
