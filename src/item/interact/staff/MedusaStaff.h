#ifndef PATHOS_MEDUSA_STAFF
#define PATHOS_MEDUSA_STAFF

#include "item/interact/staff/Staff.h"

namespace Pathos {

// Staff made by Medusa materials.
class MedusaStaff : public Staff {
public:
  MedusaStaff() : Staff(195000, 450000, 900000) {}
};

} // namespace Pathos

#endif // PATHOS_MEDUSA_STAFF
