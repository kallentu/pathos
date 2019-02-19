#include "mob/friendly/Poseidon.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Poseidon::beTalkedToBy(Player &p) {
  (void)p;
  return std::make_unique<TalkRequest>(
      "The sea has been shaken by what you've accomplished.");
}
