#include "mob/friendly/merchant/Blacksmith.h"
#include "mob/player/Player.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> Blacksmith::beTalkedToBy(Player &p) {
  return std::make_unique<TalkRequest>(
      "Welcome " + p.getName() +
      "! I have stock available for your every weapon need, from greatswords "
      "to bows to staffs. We have them all.");
}
