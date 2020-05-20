#include "mode/QuestMode.h"
#include <memory>

using namespace Pathos;

QuestMode::QuestMode(PathosInstance *inst, QuestGiver *questGiver)
    : Mode(inst), handler{std::make_unique<QuestModeHandler>(inst, questGiver)} {}

ModeHandler *QuestMode::getHandler() const { return handler.get(); }
