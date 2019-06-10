#ifndef PATHOS_QUEST_MODE
#define PATHOS_QUEST_MODE

#include "mode/Mode.h"
#include "mode/handler/QuestModeHandler.h"
#include <memory>

namespace Pathos {

class PathosInstance;
class ModeHandler;
class Quest;

// Mode where the player needs to do quest acceptance/interaction.
class QuestMode : public Mode {
  Quest *quest;
  std::unique_ptr<QuestModeHandler> handler;

public:
  QuestMode(PathosInstance *inst, Quest *quest);

  ModeHandler *getHandler() const override;
  Quest *getQuest();
};

} // namespace Pathos

#endif // PATHOS_QUEST_MODE
