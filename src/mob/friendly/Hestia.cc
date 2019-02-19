#include "mob/friendly/Hestia.h"
#include "mob/player/Player.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Hestia::beTalkedToBy(Player &p) {
  return std::make_unique<TalkRequest>(
      p.getName() +
      " dear, you don't look well. Come rest, I will make a hearth.");
}
