#ifndef PATHOS_HYDRA_BOW
#define PATHOS_HYDRA_BOW

#include "item/equip/bow/Bow.h"
#include <string>

namespace Pathos {

// Bow made by Hydra materials.
class HydraBow : public Bow {
public:
  HydraBow() : Bow("hydra", 750, 7500, 14000) {}
};

} // namespace Pathos

#endif // PATHOS_HYDRA_BOW
