#include "mob/friendly/Demeter.h"
#include "mob/player/Player.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Demeter::beTalkedToBy(Player &p) {
  return std::make_unique<TalkRequest>(
      p.getName() + "Have you seen my daughter, Persephone?");
}
