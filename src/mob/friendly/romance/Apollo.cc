#include "mob/friendly/romance/Apollo.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Apollo::talkedToBy(Player &p) {
  (void)p;
  return std::make_unique<TalkRequest>(
      "With my music, I can liberate you from your pain and anguish.");
}
