#ifndef PATHOS_ARACHNE_BOW
#define PATHOS_ARACHNE_BOW

#include "item/interact/bow/Bow.h"

namespace Pathos {

// Bow made by Arachne materials.
class ArachneBow : public Bow {
public:
  ArachneBow() : Bow(70000, 500000, 1000000) {}
};

} // namespace Pathos

#endif // PATHOS_ARACHNE_BOW
