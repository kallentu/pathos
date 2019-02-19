#include "mob/friendly/Hera.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Hera::beTalkedToBy(Player &p) {
  (void)p;
  return std::make_unique<TalkRequest>("Zeus must be up to something. I have "
                                       "to check on his affairs; Where is he?");
}
