#ifndef PATHOS_MERCHANT
#define PATHOS_MERCHANT

#include "mob/friendly/Friendly.h"
#include "mob/friendly/merchant/Trader.h"
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace Pathos {

class Item;

class Merchant : public Friendly, public Trader {
public:
  explicit Merchant(std::string name) : Friendly(std::move(name)), Trader() {}
  
private:
  // Used when constructing Merchant.
  virtual void initializeStock() = 0;
};

} // namespace Pathos

#endif // PATHOS_MERCHANT
