#ifndef PATHOS_QUEST_MODE_HANDLER
#define PATHOS_QUEST_MODE_HANDLER

#include "mode/handler/ModeHandler.h"
#include "quest/Quest.h"
#include <memory>
#include <string>

namespace Pathos {

  class Event;

  class Char;

// Parses keys for updating and interacting with QuestGivers.
  class QuestModeHandler : public ModeHandler {
    Quest *quest;
    QuestGiver *questGiver;
    std::string input;

  public:
    QuestModeHandler(PathosInstance *inst, QuestGiver *questGiver);

    std::unique_ptr<Event> handle(const Char &c) override;

  private:
    std::unique_ptr<Event> parseEvent(int index);
  };

} // namespace Pathos

#endif // PATHOS_QUEST_MODE_HANDLER
