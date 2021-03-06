#ifndef PATHOS_PETRIFIED_BOW
#define PATHOS_PETRIFIED_BOW

#include "item/equip/bow/Bow.h"
#include <string>

namespace Pathos {

// Bow made by Petrified God materials.
class PetrifiedBow : public Bow {
public:
  PetrifiedBow() : Bow("petrified", 45000, 175000, 350000) {}
};

} // namespace Pathos

#endif // PATHOS_PETRIFIED_BOW
