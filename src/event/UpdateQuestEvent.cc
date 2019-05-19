#include "event/UpdateQuestEvent.h"
#include "core/PathosInstance.h"
#include "quest/Quest.h"

using namespace Pathos;

void UpdateQuestEvent::begin(PathosInstance *inst) {
  quest->updateQuestStatus(inst);
}
