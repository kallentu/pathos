#ifndef PATHOS_CENTAUR_GREATSWORD
#define PATHOS_CENTAUR_GREATSWORD

#include "item/interact/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Centaur materials.
class CentaurGreatsword : public Greatsword {
public:
  CentaurGreatsword() : Greatsword(300, 1000, 2000) {}
};

} // namespace Pathos

#endif // PATHOS_CENTAUR_GREATSWORD
