#ifndef PATHOS_CENTAUR_BOW
#define PATHOS_CENTAUR_BOW

#include "item/equip/bow/Bow.h"
#include <string>

namespace Pathos {

// Bow made by Centaur materials.
class CentaurBow : public Bow {
public:
  CentaurBow() : Bow("centaur", 100, 1000, 2000) {}
};

} // namespace Pathos

#endif // PATHOS_CENTAUR_BOW
