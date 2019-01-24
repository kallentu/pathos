#ifndef PATHOS_MINOTAUR_BOW
#define PATHOS_MINOTAUR_BOW

#include "item/equip/bow/Bow.h"

namespace Pathos {

// Bow made by Minotaur materials.
class MinotaurBow : public Bow {
public:
  MinotaurBow() : Bow(15000, 50000, 100000) {}
};

} // namespace Pathos

#endif // PATHOS_MINOTAUR_BOW
