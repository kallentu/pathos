#ifndef PATHOS_CHIMERA_BOW
#define PATHOS_CHIMERA_BOW

#include "item/equip/bow/Bow.h"
#include <string>

namespace Pathos {

// Bow made by Chimera materials.
class ChimeraBow : public Bow {
public:
  ChimeraBow() : Bow("chimera", 1000, 10000, 20000) {}
};

} // namespace Pathos

#endif // PATHOS_CHIMERA_BOW
