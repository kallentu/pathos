#ifndef PATHOS_HARPY_GREATSWORD
#define PATHOS_HARPY_GREATSWORD

#include "item/interact/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Harpy materials.
class HarpyGreatsword : public Greatsword {
public:
  HarpyGreatsword() : Greatsword(155000, 300000, 400000) {}
};

} // namespace Pathos

#endif // PATHOS_HARPY_GREATSWORD
