#ifndef PATHOS_WALL
#define PATHOS_WALL

#include "map/MapObject.h"

namespace Pathos {

class Wall : public MapObject {
public:
  Wall() : MapObject(MapObject::Char::Bound) {}
  ~Wall() override = default;
};

} // namespace Pathos

#endif // PATHOS_WALL
