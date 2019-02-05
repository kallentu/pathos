#include "mob/friendly/romance/Romanceable.h"
#include "mob/player/Player.h"

using namespace Pathos;

// TODO: marriage
void Romanceable::beMarriedBy(Player &p) {}

// TODO: gifting
// Since no inventory from friendly, gift released.
void Romanceable::beGiftedBy(std::unique_ptr<Item> it, Player &p) {}

void Romanceable::beTalkedToBy(Player &p) {
  romanceExp++;
  talkedToBy(p);
}
