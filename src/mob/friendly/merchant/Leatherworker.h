#ifndef PATHOS_LEATHERWORKER
#define PATHOS_LEATHERWORKER

#include "mob/friendly/merchant/Merchant.h"

namespace Pathos {

// Merchant who sells/buys armor.
class Leatherworker : public Merchant {
public:
  Leatherworker() : Merchant() { initializeStock(); }

private:
  // TODO: Once there are defined armor creation
  void initializeStock() override {}
};

} // namespace Pathos

#endif // PATHOS_LEATHERWORKER
