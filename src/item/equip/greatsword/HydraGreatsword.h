#ifndef PATHOS_HYDRA_GREATSWORD
#define PATHOS_HYDRA_GREATSWORD

#include "item/equip/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Hydra materials.
class HydraGreatsword : public Greatsword {
public:
  HydraGreatsword() : Greatsword(2250, 7500, 14000) {}
};

} // namespace Pathos

#endif // PATHOS_HYDRA_GREATSWORD
