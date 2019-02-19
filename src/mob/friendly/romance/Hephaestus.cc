#include "mob/friendly/romance/Hephaestus.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Hephaestus::talkedToBy(Player &p) {
  (void)p;
  return std::make_unique<TalkRequest>(
      "With the right tools, you can conquer anything!");
}
