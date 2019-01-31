#ifndef PATHOS_HARPY_GREATSWORD
#define PATHOS_HARPY_GREATSWORD

#include "item/equip/greatsword/Greatsword.h"
#include <string>

namespace Pathos {

// Greatsword made from Harpy materials.
class HarpyGreatsword : public Greatsword {
public:
  HarpyGreatsword() : Greatsword("harpy", 155000, 300000, 400000) {}
};

} // namespace Pathos

#endif // PATHOS_HARPY_GREATSWORD
