#include "event/UpdateQuestEvent.h"
#include "core/PathosInstance.h"
#include "quest/Quest.h"
#include "quest/QuestManager.h"
#include "request/ClearEntireStatus.h"
#include "request/MultipleRequest.h"
#include "request/QuestRequest.h"

using namespace Pathos;

void UpdateQuestEvent::begin(PathosInstance *inst) {
  // Update the conditions and status of the quest if they changed.
  quest->updateQuestStatus(inst);

  // Clear prior main and quick status since we moved.
  // Update view depending on quest progress.
  std::unique_ptr<MultipleRequest> request = std::make_unique<MultipleRequest>();
  request->addRequest(std::make_unique<ClearEntireStatus>());
  request->addRequest(quest->getQuestGiver()->haveQuestRequestRetrievedBy(QuestManager::instance(), inst));
  inst->notify(request.get());
}
