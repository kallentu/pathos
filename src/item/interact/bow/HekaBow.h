#ifndef PATHOS_HEKA_BOW
#define PATHOS_HEKA_BOW

#include "item/interact/bow/Bow.h"

namespace Pathos {

// Bow made by Hekatonkheires materials.
class HekaBow : public Bow {
public:
  HekaBow() : Bow(50000, 250000, 500000) {}
};

} // namespace Pathos

#endif // PATHOS_HEKA_BOW
