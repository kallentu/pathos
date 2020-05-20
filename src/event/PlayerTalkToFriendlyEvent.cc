#include "event/PlayerTalkToFriendlyEvent.h"
#include "core/PathosInstance.h"
#include "mob/player/Player.h"

using namespace Pathos;

void PlayerTalkToFriendlyEvent::begin(PathosInstance *inst) {
  Player *player = inst->getPlayer();
  std::unique_ptr<TalkRequest> talkReq = player->talkTo(friendly);
  inst->notify(talkReq.get());
}
