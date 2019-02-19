#include "mob/friendly/romance/Tyche.h"
#include "mob/player/Player.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Tyche::talkedToBy(Player &p) {
  return std::make_unique<TalkRequest>(
      "Destiny is unavoidable. What do you need " + p.getName() + "?");
}
