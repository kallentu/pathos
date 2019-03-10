#ifndef PATHOS_MERCHANT
#define PATHOS_MERCHANT

#include "event/EventManager.h"
#include "mob/friendly/Friendly.h"
#include "mob/friendly/merchant/Trader.h"
#include <memory>
#include <string>
#include <vector>

namespace Pathos {

class Item;

class Merchant : public Friendly, public Trader {
public:
  Merchant(std::string name) : Friendly(name), Trader() {}

  std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) override {
    return em->getEventList(*this);
  }

private:
  // Used when constructing Merchant.
  virtual void initializeStock() = 0;
};

} // namespace Pathos

#endif // PATHOS_MERCHANT
