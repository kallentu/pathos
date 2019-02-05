#ifndef PATHOS_GENERAL_MERCHANT
#define PATHOS_GENERAL_MERCHANT

#include "mob/friendly/merchant/Merchant.h"

namespace Pathos {

// Merchant who sells/buys consumables.
class GeneralMerchant : public Merchant {
public:
  GeneralMerchant() : Merchant() { initializeStock(); }

private:
  // TODO: Once there are defined item creation
  void initializeStock() override {}
};

} // namespace Pathos

#endif // PATHOS_GENERAL_MERCHANT
