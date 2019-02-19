#include "mob/friendly/romance/Artemis.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Artemis::talkedToBy(Player &p) {
  (void)p;
  return std::make_unique<TalkRequest>(
      "Challenge me! Nobody is a better hunter than I.");
}
