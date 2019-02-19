#include "mob/friendly/merchant/GeneralMerchant.h"
#include "request/TalkRequest.h"
#include <memory>

using namespace Pathos;

std::unique_ptr<TalkRequest> GeneralMerchant::beTalkedToBy(Player &p) {
  (void)p;
  return std::make_unique<TalkRequest>(
      "Have a refresher. I have many potions and good wares, take a look.");
}
