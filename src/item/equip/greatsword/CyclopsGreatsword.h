#ifndef PATHOS_CYCLOPS_GREATSWORD
#define PATHOS_CYCLOPS_GREATSWORD

#include "item/equip/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Vengeful Cyclops materials.
class CyclopsGreatsword : public Greatsword {
public:
  CyclopsGreatsword() : Greatsword(125000, 150000, 300000) {}
};

} // namespace Pathos

#endif // PATHOS_CYCLOPS_GREATSWORD
