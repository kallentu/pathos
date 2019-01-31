#ifndef PATHOS_HEKA_STAFF
#define PATHOS_HEKA_STAFF

#include "item/equip/staff/Staff.h"
#include <string>

namespace Pathos {

// Staff made by Hekatonkheires materials.
class HekaStaff : public Staff {
public:
  HekaStaff() : Staff("heka", 150000, 250000, 500000) {}
};

} // namespace Pathos

#endif // PATHOS_HEKA_STAFF
