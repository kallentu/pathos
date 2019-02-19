#include "mob/friendly/romance/Hermes.h"
#include "mob/player/Player.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Hermes::talkedToBy(Player &p) {
  return std::make_unique<TalkRequest>(
      "Honestly, the gods are so boring... Tell me what you need " +
      p.getName() + ", I will get it done with a little flair here and there.");
}
