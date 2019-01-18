#ifndef PATHOS_HYDRA_STAFF
#define PATHOS_HYDRA_STAFF

#include "item/interact/staff/Staff.h"

namespace Pathos {

// Staff made by Hydra materials.
class HydraStaff : public Staff {
public:
  HydraStaff() : Staff(2250, 7500, 14000) {}
};

} // namespace Pathos

#endif // PATHOS_HYDRA_STAFF
