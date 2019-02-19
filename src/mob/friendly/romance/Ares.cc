#include "mob/friendly/romance/Ares.h"
#include "mob/player/Player.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Ares::talkedToBy(Player &p) {
  return std::make_unique<TalkRequest>(
      p.getName() + ", I will follow you into war and onwards!");
}
