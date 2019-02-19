#include "mob/friendly/romance/Dionysus.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Dionysus::talkedToBy(Player &p) {
  (void)p;
  return std::make_unique<TalkRequest>(
      "Wine and entertainment, there is no finer afternoon.");
}
