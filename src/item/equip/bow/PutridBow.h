#ifndef PATHOS_PUTRID_BOW
#define PATHOS_PUTRID_BOW

#include "item/equip/bow/Bow.h"
#include <string>

namespace Pathos {

// Bow made by Putrid Bile materials.
class PutridBow : public Bow {
public:
  PutridBow() : Bow("putrid", 12000, 40000, 80000) {}
};

} // namespace Pathos

#endif // PATHOS_PUTRID_BOW
