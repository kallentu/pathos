#ifndef PATHOS_PUTRID_GREATSWORD
#define PATHOS_PUTRID_GREATSWORD

#include "item/interact/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Putrid Bile materials.
class PutridGreatsword : public Greatsword {
public:
  PutridGreatsword() : Greatsword(40000, 40000, 80000) {}
};

} // namespace Pathos

#endif // PATHOS_PUTRID_GREATSWORD
