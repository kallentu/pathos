#ifndef PATHOS_SCYLLA_BOW
#define PATHOS_SCYLLA_BOW

#include "item/interact/bow/Bow.h"

namespace Pathos {

// Bow made by Scylla materials.
class ScyllaBow : public Bow {
public:
  ScyllaBow() : Bow(300, 3000, 6000) {}
};

} // namespace Pathos

#endif // PATHOS_SCYLLA_BOW
