#ifndef PATHOS_ARACHNE_GREATSWORD
#define PATHOS_ARACHNE_GREATSWORD

#include "item/equip/greatsword/Greatsword.h"
#include <string>

namespace Pathos {

// Greatsword made from Arachne materials.
class ArachneGreatsword : public Greatsword {
public:
  ArachneGreatsword() : Greatsword("arachne", 200000, 500000, 1000000) {}
};

} // namespace Pathos

#endif // PATHOS_ARACHNE_GREATSWORD
