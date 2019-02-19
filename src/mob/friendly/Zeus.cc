#include "mob/friendly/Zeus.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Zeus::beTalkedToBy(Player &p) {
  (void)p;
  return std::make_unique<TalkRequest>(
      "When you need me, lightning will be by your side.");
}
