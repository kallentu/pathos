#ifndef PATHOS_GROUND
#define PATHOS_GROUND

#include "event/Event.h"
#include "map/MapObject.h"

namespace Pathos {

class Ground : public MapObject {
public:
  Ground() : MapObject(MapObject::Char::Empty) {}
  ~Ground() override = default;
};

} // namespace Pathos

#endif // PATHOS_GROUND
