#ifndef PATHOS_MINOTAUR_STAFF
#define PATHOS_MINOTAUR_STAFF

#include "item/interact/staff/Staff.h"

namespace Pathos {

// Staff made by Minotaur materials.
class MinotaurStaff : public Staff {
public:
  MinotaurStaff() : Staff(43000, 50000, 100000) {}
};

} // namespace Pathos

#endif // PATHOS_MINOTAUR_STAFF
