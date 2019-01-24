#ifndef PATHOS_PETRIFIED_STAFF
#define PATHOS_PETRIFIED_STAFF

#include "item/equip/staff/Staff.h"

namespace Pathos {

// Staff made by Petrified God materials.
class PetrifiedStaff : public Staff {
public:
  PetrifiedStaff() : Staff(130000, 175000, 350000) {}
};

} // namespace Pathos

#endif // PATHOS_PETRIFIED_STAFF
