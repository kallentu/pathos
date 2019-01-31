#ifndef PATHOS_WOLF_BOW
#define PATHOS_WOLF_BOW

#include "item/equip/bow/Bow.h"
#include <string>

namespace Pathos {

// Bow made by Wolf materials.
class WolfBow : public Bow {
public:
  WolfBow() : Bow("wolf", 15, 100, 200) {}
};

} // namespace Pathos

#endif // PATHOS_WOLF_BOW
