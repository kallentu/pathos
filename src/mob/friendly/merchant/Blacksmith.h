#ifndef PATHOS_BLACKSMITH
#define PATHOS_BLACKSMITH

#include "mob/friendly/merchant/Merchant.h"

namespace Pathos {

// Merchant who sells/buys weapons.
class Blacksmith : public Merchant {
public:
  Blacksmith() : Merchant() { initializeStock(); }

private:
  // TODO: Once there are defined weapon creation
  void initializeStock() override {}
};

} // namespace Pathos

#endif // PATHOS_BLACKSMITH
