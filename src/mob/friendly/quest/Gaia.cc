#include "mob/friendly/quest/Gaia.h"
#include "core/PathosInstance.h"
#include "mob/player/Player.h"
#include "quest/QuestManager.h"
#include "request/QuestRequest.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Gaia::beTalkedToBy(Player &p) {
  return std::make_unique<TalkRequest>(
      "Be at peace, " + p.getName() +
      "... There is so much more to discover and explore in the world.");
}

std::unique_ptr<QuestRequest>
Gaia::haveQuestRequestRetrievedBy(QuestManager *qm, PathosInstance *inst) {
  return qm->getQuestRequest(*this, inst);
}
