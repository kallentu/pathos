#ifndef PATHOS_CHAOS_GREATSWORD
#define PATHOS_CHAOS_GREATSWORD

#include "item/interact/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Chaos materials.
class ChaosGreatsword : public Greatsword {
public:
  ChaosGreatsword() : Greatsword(280000, 750000, 1500000) {}
};

} // namespace Pathos

#endif // PATHOS_CHAOS_GREATSWORD
