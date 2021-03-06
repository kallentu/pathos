#ifndef PATHOS_CHIMERA_GREATSWORD
#define PATHOS_CHIMERA_GREATSWORD

#include "item/equip/greatsword/Greatsword.h"
#include <string>

namespace Pathos {

// Greatsword made from Chimera materials.
class ChimeraGreatsword : public Greatsword {
public:
  ChimeraGreatsword() : Greatsword("chimera", 3000, 10000, 20000) {}
};

} // namespace Pathos

#endif // PATHOS_CHIMERA_GREATSWORD
