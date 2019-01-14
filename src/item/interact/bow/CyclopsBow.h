#ifndef PATHOS_CYCLOPS_BOW
#define PATHOS_CYCLOPS_BOW

#include "item/interact/bow/Bow.h"

namespace Pathos {

// Bow made by Vengeful Cyclops materials.
class CyclopsBow : public Bow {
public:
  CyclopsBow() : Bow(40000, 150000, 300000) {}
};

} // namespace Pathos

#endif // PATHOS_CYCLOPS_BOW
