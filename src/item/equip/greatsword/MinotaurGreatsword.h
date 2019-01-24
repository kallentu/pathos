#ifndef PATHOS_MINOTAUR_GREATSWORD
#define PATHOS_MINOTAUR_GREATSWORD

#include "item/equip/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Minotaur materials.
class MinotaurGreatsword : public Greatsword {
public:
  MinotaurGreatsword() : Greatsword(43000, 50000, 100000) {}
};

} // namespace Pathos

#endif // PATHOS_MINOTAUR_GREATSWORD
