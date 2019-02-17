#ifndef PATHOS_LEATHERWORKER
#define PATHOS_LEATHERWORKER

#include "mob/friendly/merchant/Merchant.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// Merchant who sells/buys armor.
class Leatherworker : public Merchant {
public:
  Leatherworker() : Merchant() { initializeStock(); }

private:
  // TODO: Once there are defined armor creation
  void initializeStock() override {}

  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_LEATHERWORKER
