#ifndef PATHOS_MEDUSA_STAFF
#define PATHOS_MEDUSA_STAFF

#include "item/equip/staff/Staff.h"
#include <string>

namespace Pathos {

// Staff made by Medusa materials.
class MedusaStaff : public Staff {
public:
  MedusaStaff() : Staff("medusa", 195000, 450000, 900000) {}
};

} // namespace Pathos

#endif // PATHOS_MEDUSA_STAFF
