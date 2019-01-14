#ifndef PATHOS_CHIMERA_BOW
#define PATHOS_CHIMERA_BOW

#include "item/interact/bow/Bow.h"

namespace Pathos {

// Bow made by Chimera materials.
class ChimeraBow : public Bow {
public:
  ChimeraBow() : Bow(1000, 10000, 20000) {}
};

} // namespace Pathos

#endif // PATHOS_CHIMERA_BOW
