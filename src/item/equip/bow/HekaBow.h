#ifndef PATHOS_HEKA_BOW
#define PATHOS_HEKA_BOW

#include "item/equip/bow/Bow.h"
#include <string>

namespace Pathos {

// Bow made by Hekatonkheires materials.
class HekaBow : public Bow {
public:
  HekaBow() : Bow("heka", 50000, 250000, 500000) {}
};

} // namespace Pathos

#endif // PATHOS_HEKA_BOW
