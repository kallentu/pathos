#ifndef PATHOS_MAP
#define PATHOS_MAP

#include <vector>

#include "map/MapObject.h"

namespace Pathos {

class Map {
  std::vector<std::vector<MapObject>> map;

public:
  // TODO:
  Map(MapObject *m) {}
  virtual ~Map() {}
};

} // namespace Pathos

#endif // PATHOS_MAP
