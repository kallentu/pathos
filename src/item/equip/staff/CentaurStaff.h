#ifndef PATHOS_CENTAUR_STAFF
#define PATHOS_CENTAUR_STAFF

#include "item/equip/staff/Staff.h"
#include <string>

namespace Pathos {

// Staff made by Centaur materials.
class CentaurStaff : public Staff {
public:
  CentaurStaff() : Staff("centaur", 300, 1000, 2000) {}
};

} // namespace Pathos

#endif // PATHOS_CENTAUR_STAFF
