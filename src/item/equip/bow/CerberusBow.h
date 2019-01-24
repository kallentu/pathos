#ifndef PATHOS_CERBERUS_BOW
#define PATHOS_CERBERUS_BOW

#include "item/equip/bow/Bow.h"

namespace Pathos {

// Bow made by Cerberus materials.
class CerberusBow : public Bow {
public:
  CerberusBow() : Bow(5000, 20000, 40000) {}
};

} // namespace Pathos

#endif // PATHOS_CERBERUS_BOW
