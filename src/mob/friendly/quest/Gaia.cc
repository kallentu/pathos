#include "mob/friendly/quest/Gaia.h"
#include "mob/player/Player.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Gaia::beTalkedToBy(Player &p) {
  return std::make_unique<TalkRequest>(
      "Be at peace, " + p.getName() +
      "... There is so much more to discover and explore in the world.");
}
