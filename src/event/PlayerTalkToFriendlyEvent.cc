#include "event/PlayerTalkToFriendlyEvent.h"
#include "core/PathosInstance.h"
#include "mob/friendly/Friendly.h"
#include "mob/player/Player.h"
#include "view/curses/NcursesView.h"

using namespace Pathos;

void PlayerTalkToFriendlyEvent::begin(PathosInstance *inst) {
  Player *player = inst->getPlayer();
  TalkRequest *talkReq = player->talkTo(friendly).get();
  talkReq->beDrawnBy(*(inst->getView()));
}
