#ifndef PATHOS_CERBERUS_STAFF
#define PATHOS_CERBERUS_STAFF

#include "item/equip/staff/Staff.h"

namespace Pathos {

// Staff made by Cerberus materials.
class CerberusStaff : public Staff {
public:
  CerberusStaff() : Staff(14500, 20000, 40000) {}
};

} // namespace Pathos

#endif // PATHOS_CERBERUS_STAFF
