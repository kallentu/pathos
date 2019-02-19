#include "mob/friendly/romance/Aphrodite.h"
#include "mob/player/Player.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Aphrodite::talkedToBy(Player &p) {
  return std::make_unique<TalkRequest>(
      "I help all those who value beauty and vanity. You, " + p.getName() +
      ", look divine...");
}
