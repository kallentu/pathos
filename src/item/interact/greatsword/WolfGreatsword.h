#ifndef PATHOS_WOLF_GREATSWORD
#define PATHOS_WOLF_GREATSWORD

#include "item/interact/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Wolf materials.
class WolfGreatsword : public Greatsword {
public:
  WolfGreatsword() : Greatsword(30, 100, 200) {}
};

} // namespace Pathos

#endif // PATHOS_WOLF_GREATSWORD
