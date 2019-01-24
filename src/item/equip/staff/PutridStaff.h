#ifndef PATHOS_PUTRID_STAFF
#define PATHOS_PUTRID_STAFF

#include "item/equip/staff/Staff.h"

namespace Pathos {

// Staff made by Putrid Bile materials.
class PutridStaff : public Staff {
public:
  PutridStaff() : Staff(40000, 40000, 80000) {}
};

} // namespace Pathos

#endif // PATHOS_PUTRID_STAFF
