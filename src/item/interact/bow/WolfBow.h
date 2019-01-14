#ifndef PATHOS_WOLF_BOW
#define PATHOS_WOLF_BOW

#include "item/interact/bow/Bow.h"

namespace Pathos {

// Bow made by Wolf materials.
class WolfBow : public Bow {
public:
  WolfBow() : Bow(15, 100, 200) {}
};

} // namespace Pathos

#endif // PATHOS_WOLF_BOW
