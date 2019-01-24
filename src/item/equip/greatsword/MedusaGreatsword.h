#ifndef PATHOS_MEDUSA_GREATSWORD
#define PATHOS_MEDUSA_GREATSWORD

#include "item/equip/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Medusa materials.
class MedusaGreatsword : public Greatsword {
public:
  MedusaGreatsword() : Greatsword(190000, 450000, 900000) {}
};

} // namespace Pathos

#endif // PATHOS_MEDUSA_GREATSWORD
