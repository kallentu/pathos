#ifndef PATHOS_HEKA_GREATSWORD
#define PATHOS_HEKA_GREATSWORD

#include "item/equip/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Hekatonkheires materials.
class HekaGreatsword : public Greatsword {
public:
  HekaGreatsword() : Greatsword(150000, 250000, 500000) {}
};

} // namespace Pathos

#endif // PATHOS_HEKA_GREATSWORD
