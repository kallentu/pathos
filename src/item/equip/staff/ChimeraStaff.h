#ifndef PATHOS_CHIMERA_STAFF
#define PATHOS_CHIMERA_STAFF

#include "item/equip/staff/Staff.h"
#include <string>

namespace Pathos {

// Staff made by Chimera materials.
class ChimeraStaff : public Staff {
public:
  ChimeraStaff() : Staff("chimera", 3000, 10000, 20000) {}
};

} // namespace Pathos

#endif // PATHOS_CHIMERA_STAFF
