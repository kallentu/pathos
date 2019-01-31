#ifndef PATHOS_CYCLOPS_STAFF
#define PATHOS_CYCLOPS_STAFF

#include "item/equip/staff/Staff.h"
#include <string>

namespace Pathos {

// Staff made by Vengeful Cyclops materials.
class CyclopsStaff : public Staff {
public:
  CyclopsStaff() : Staff("cyclops", 125000, 150000, 300000) {}
};

} // namespace Pathos

#endif // PATHOS_CYCLOPS_STAFF
