#ifndef PATHOS_GENERAL_MERCHANT
#define PATHOS_GENERAL_MERCHANT

#include "mob/friendly/merchant/Merchant.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// Merchant who sells/buys consumables.
class GeneralMerchant : public Merchant {
public:
  GeneralMerchant() : Merchant("General Merchant") { initializeStock(); }

private:
  // TODO: Once there are defined item creation
  void initializeStock() override {}

  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_GENERAL_MERCHANT
