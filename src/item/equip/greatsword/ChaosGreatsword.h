#ifndef PATHOS_CHAOS_GREATSWORD
#define PATHOS_CHAOS_GREATSWORD

#include "item/equip/greatsword/Greatsword.h"
#include <string>

namespace Pathos {

// Greatsword made from Chaos materials.
class ChaosGreatsword : public Greatsword {
public:
  ChaosGreatsword() : Greatsword("chaos", 280000, 750000, 1500000) {}
};

} // namespace Pathos

#endif // PATHOS_CHAOS_GREATSWORD
