#ifndef PATHOS_WOLF_STAFF
#define PATHOS_WOLF_STAFF

#include "item/equip/staff/Staff.h"
#include <string>

namespace Pathos {

// Staff made by Wolf materials.
class WolfStaff : public Staff {
public:
  WolfStaff() : Staff("wolf", 30, 100, 200) {}
};

} // namespace Pathos

#endif // PATHOS_WOLF_STAFF
