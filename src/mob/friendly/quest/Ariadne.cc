#include "mob/friendly/quest/Ariadne.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Ariadne::beTalkedToBy(Player &p) {
  (void)p;
  return std::make_unique<TalkRequest>(
      "I continue to study the wonders of the Labyrinth...");
}
