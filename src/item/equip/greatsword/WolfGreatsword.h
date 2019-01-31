#ifndef PATHOS_WOLF_GREATSWORD
#define PATHOS_WOLF_GREATSWORD

#include "item/equip/greatsword/Greatsword.h"
#include <string>

namespace Pathos {

// Greatsword made from Wolf materials.
class WolfGreatsword : public Greatsword {
public:
  WolfGreatsword() : Greatsword("wolf", 30, 100, 200) {}
};

} // namespace Pathos

#endif // PATHOS_WOLF_GREATSWORD
