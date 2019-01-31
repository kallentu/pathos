#ifndef PATHOS_CYCLOPS_BOW
#define PATHOS_CYCLOPS_BOW

#include "item/equip/bow/Bow.h"
#include <string>

namespace Pathos {

// Bow made by Vengeful Cyclops materials.
class CyclopsBow : public Bow {
public:
  CyclopsBow() : Bow("cyclops", 40000, 150000, 300000) {}
};

} // namespace Pathos

#endif // PATHOS_CYCLOPS_BOW
