#ifndef PATHOS_HARPY_STAFF
#define PATHOS_HARPY_STAFF

#include "item/equip/staff/Staff.h"
#include <string>

namespace Pathos {

// Staff made by Harpy materials.
class HarpyStaff : public Staff {
public:
  HarpyStaff() : Staff("harpy", 155000, 300000, 400000) {}
};

} // namespace Pathos

#endif // PATHOS_HARPY_STAFF
