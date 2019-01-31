#ifndef PATHOS_SCYLLA_BOW
#define PATHOS_SCYLLA_BOW

#include "item/equip/bow/Bow.h"
#include <string>

namespace Pathos {

// Bow made by Scylla materials.
class ScyllaBow : public Bow {
public:
  ScyllaBow() : Bow("scylla", 300, 3000, 6000) {}
};

} // namespace Pathos

#endif // PATHOS_SCYLLA_BOW
