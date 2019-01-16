#ifndef PATHOS_PETRIFIED_GREATSWORD
#define PATHOS_PETRIFIED_GREATSWORD

#include "item/interact/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Petrified God materials.
class PetrifiedGreatsword : public Greatsword {
public:
  PetrifiedGreatsword() : Greatsword(130000, 175000, 350000) {}
};

} // namespace Pathos

#endif // PATHOS_PETRIFIED_GREATSWORD
