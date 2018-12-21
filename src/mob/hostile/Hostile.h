#ifndef PATHOS_HOSTILE
#define PATHOS_HOSTILE

#include "map/MapObject.h"

namespace Pathos {

class Hostile : MapObject {
public:
  Hostile() : MapObject(MapObject::Char::Lantern) {}
  virtual ~Hostile() {}
};

} // namespace Pathos

#endif // PATHOS_HOSTILE
