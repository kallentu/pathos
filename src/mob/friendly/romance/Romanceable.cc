#include "mob/friendly/romance/Romanceable.h"
#include "mob/player/Player.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

// TODO: marriage
void Romanceable::beMarriedBy(Player &p) {}

// TODO: gifting
// Since no inventory from friendly, gift released.
void Romanceable::beGiftedBy(std::unique_ptr<Item> it, Player &p) {}

std::unique_ptr<TalkRequest> Romanceable::beTalkedToBy(Player &p) {
  romanceExp++;
  return talkedToBy(p);
}
