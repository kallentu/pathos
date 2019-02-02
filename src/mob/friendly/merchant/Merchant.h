#ifndef PATHOS_MERCHANT
#define PATHOS_MERCHANT

#include "mob/friendly/Friendly.h"
#include "mob/friendly/merchant/Trader.h"

namespace Pathos {

class Item;

class Merchant : public Friendly, public Trader {
public:
  Merchant() : Friendly(), Trader() {}

private:
  // Used when constructing Merchant.
  virtual void initializeStock() = 0;
};

} // namespace Pathos

#endif // PATHOS_MERCHANT
