#ifndef PATHOS_SCYLLA_STAFF
#define PATHOS_SCYLLA_STAFF

#include "item/equip/staff/Staff.h"
#include <string>

namespace Pathos {

// Staff made by Scylla materials.
class ScyllaStaff : public Staff {
public:
  ScyllaStaff() : Staff("scylla", 900, 3000, 6000) {}
};

} // namespace Pathos

#endif // PATHOS_SCYLLA_STAFF
