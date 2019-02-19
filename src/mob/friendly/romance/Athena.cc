#include "mob/friendly/romance/Athena.h"
#include "mob/player/Player.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Athena::talkedToBy(Player &p) {
  return std::make_unique<TalkRequest>(
      "Remember " + p.getName() +
      ", wisdom is not all that one needs in order to succeed.");
}
