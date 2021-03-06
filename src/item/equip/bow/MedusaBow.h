#ifndef PATHOS_MEDUSA_BOW
#define PATHOS_MEDUSA_BOW

#include "item/equip/bow/Bow.h"
#include <string>

namespace Pathos {

// Bow made by Medusa materials.
class MedusaBow : public Bow {
public:
  MedusaBow() : Bow("medusa", 72000, 450000, 900000) {}
};

} // namespace Pathos

#endif // PATHOS_MEDUSA_BOW
