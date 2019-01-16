#ifndef PATHOS_SCYLLA_GREATSWORD
#define PATHOS_SCYLLA_GREATSWORD

#include "item/interact/greatsword/Greatsword.h"

namespace Pathos {

// Greatsword made from Scylla materials.
class ScyllaGreatsword : public Greatsword {
public:
  ScyllaGreatsword() : Greatsword(900, 3000, 6000) {}
};

} // namespace Pathos

#endif // PATHOS_SCYLLA_GREATSWORD
