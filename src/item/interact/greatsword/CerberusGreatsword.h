#ifndef PATHOS_CERBERUS_GREATSWORD
#define PATHOS_CERBERUS_GREATSWORD

#include "item/interact/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Cerberus materials.
class CerberusGreatsword : public Greatsword {
public:
  CerberusGreatsword() : Greatsword(14500, 20000, 40000) {}
};

} // namespace Pathos

#endif // PATHOS_CERBERUS_GREATSWORD
