#ifndef PATHOS_GROUND
#define PATHOS_GROUND

#include "map/MapObject.h"

namespace Pathos {

class Ground : public MapObject {
public:
  Ground() : MapObject(MapObject::Char::Empty) {}
  virtual ~Ground() {}
};

} // namespace Pathos

#endif // PATHOS_GROUND
