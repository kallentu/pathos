#include "mob/friendly/Hades.h"
#include "mob/player/Player.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Hades::beTalkedToBy(Player &p) {
  return std::make_unique<TalkRequest>("Do you seek death " + p.getName() +
                                       "? Why are you here?");
}
