#ifndef PATHOS_PUTRID_GREATSWORD
#define PATHOS_PUTRID_GREATSWORD

#include "item/equip/greatsword/Greatsword.h"
#include <string>

namespace Pathos {

// Greatsword made from Putrid Bile materials.
class PutridGreatsword : public Greatsword {
public:
  PutridGreatsword() : Greatsword("putrid", 40000, 40000, 80000) {}
};

} // namespace Pathos

#endif // PATHOS_PUTRID_GREATSWORD
