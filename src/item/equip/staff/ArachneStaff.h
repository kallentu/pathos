#ifndef PATHOS_ARACHNE_STAFF
#define PATHOS_ARACHNE_STAFF

#include "item/equip/staff/Staff.h"

namespace Pathos {

// Staff made by Arachne materials.
class ArachneStaff : public Staff {
public:
  ArachneStaff() : Staff(195000, 500000, 1000000) {}
};

} // namespace Pathos

#endif // PATHOS_ARACHNE_STAFF
