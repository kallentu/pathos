#ifndef PATHOS_SCYLLA_GREATSWORD
#define PATHOS_SCYLLA_GREATSWORD

#include "item/equip/greatsword/Greatsword.h"
#include <string>

namespace Pathos {

// Greatsword made from Scylla materials.
class ScyllaGreatsword : public Greatsword {
public:
  ScyllaGreatsword() : Greatsword("scylla", 900, 3000, 6000) {}
};

} // namespace Pathos

#endif // PATHOS_SCYLLA_GREATSWORD
