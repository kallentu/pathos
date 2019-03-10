#ifndef PATHOS_BLACKSMITH
#define PATHOS_BLACKSMITH

#include "mob/friendly/merchant/Merchant.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// Merchant who sells/buys weapons.
class Blacksmith : public Merchant {
public:
  Blacksmith() : Merchant("Blacksmith") { initializeStock(); }

private:
  // TODO: Once there are defined weapon creation
  void initializeStock() override {}

  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_BLACKSMITH
