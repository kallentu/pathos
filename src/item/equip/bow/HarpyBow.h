#ifndef PATHOS_HARPY_BOW
#define PATHOS_HARPY_BOW

#include "item/equip/bow/Bow.h"
#include <string>

namespace Pathos {

// Bow made by Harpy materials.
class HarpyBow : public Bow {
public:
  HarpyBow() : Bow("harpy", 55000, 300000, 400000) {}
};

} // namespace Pathos

#endif // PATHOS_HARPY_BOW
