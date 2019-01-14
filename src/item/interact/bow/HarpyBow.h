#ifndef PATHOS_HARPY_BOW
#define PATHOS_HARPY_BOW

#include "item/interact/bow/Bow.h"

namespace Pathos {

// Bow made by Harpy materials.
class HarpyBow : public Bow {
public:
  HarpyBow() : Bow(55000, 300000, 400000) {}
};

} // namespace Pathos

#endif // PATHOS_HARPY_BOW
