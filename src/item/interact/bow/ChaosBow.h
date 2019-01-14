#ifndef PATHOS_CHAOS_BOW
#define PATHOS_CHAOS_BOW

#include "item/interact/bow/Bow.h"

namespace Pathos {

// Bow made by Chaos materials.
class ChaosBow : public Bow {
public:
  ChaosBow() : Bow(90000, 750000, 1500000) {}
};

} // namespace Pathos

#endif // PATHOS_CHAOS_BOW
