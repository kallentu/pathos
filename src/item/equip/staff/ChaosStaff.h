#ifndef PATHOS_CHAOS_STAFF
#define PATHOS_CHAOS_STAFF

#include "item/equip/staff/Staff.h"
#include <string>

namespace Pathos {

// Staff made by Chaos materials.
class ChaosStaff : public Staff {
public:
  ChaosStaff() : Staff("chaos", 280000, 750000, 1500000) {}
};

} // namespace Pathos

#endif // PATHOS_CHAOS_STAFF
