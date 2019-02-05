#ifndef PATHOS_MERCHANT
#define PATHOS_MERCHANT

#include "event/EventManager.h"
#include "mob/friendly/Friendly.h"
#include "mob/friendly/merchant/Trader.h"
#include <memory>
#include <vector>

namespace Pathos {

class Item;

class Merchant : public Friendly, public Trader {
public:
  Merchant() : Friendly(), Trader() {}

  std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) override {
    em->getEventList(*this);
  }

private:
  // Used when constructing Merchant.
  virtual void initializeStock() = 0;
};

} // namespace Pathos

#endif // PATHOS_MERCHANT
