#include "mob/friendly/merchant/Leatherworker.h"
#include "mob/player/Player.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Leatherworker::beTalkedToBy(Player &p) {
  return std::make_unique<TalkRequest>("You're looking a bit shaggy " +
                                       p.getName() +
                                       ", come buy a new set of armor!");
}
