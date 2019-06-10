#include "mode/QuestMode.h"
#include "core/PathosInstance.h"
#include "mode/handler/QuestModeHandler.h"
#include "quest/Quest.h"
#include <memory>

using namespace Pathos;

QuestMode::QuestMode(PathosInstance *inst, Quest *quest)
    : Mode(inst), quest{quest}, handler{std::make_unique<QuestModeHandler>(
                                    quest)} {}

ModeHandler *QuestMode::getHandler() const { return handler.get(); }

Quest *QuestMode::getQuest() { return quest; }
