#ifndef PATHOS_CERBERUS_BOW
#define PATHOS_CERBERUS_BOW

#include "item/equip/bow/Bow.h"
#include <string>

namespace Pathos {

// Bow made by Cerberus materials.
class CerberusBow : public Bow {
public:
  CerberusBow() : Bow("cerberus", 5000, 20000, 40000) {}
};

} // namespace Pathos

#endif // PATHOS_CERBERUS_BOW
