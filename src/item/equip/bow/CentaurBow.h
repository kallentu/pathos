#ifndef PATHOS_CENTAUR_BOW
#define PATHOS_CENTAUR_BOW

#include "item/equip/bow/Bow.h"

namespace Pathos {

// Bow made by Centaur materials.
class CentaurBow : public Bow {
public:
  CentaurBow() : Bow(100, 1000, 2000) {}
};

} // namespace Pathos

#endif // PATHOS_CENTAUR_BOW
