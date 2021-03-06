#ifndef PATHOS_MAP
#define PATHOS_MAP

#include <memory>
#include <vector>

#include "map/MapObject.h"

namespace Pathos {

class MapView;

// Maps will contain all the mob, structure and item objects that the user can
// collide or interact with.
class Map {
  // 2D grid of MapObjects.
  std::vector<std::vector<std::unique_ptr<MapObject>>> map;

public:
  // Initial map with Walls on all edges, Ground on other spaces.
  Map(size_t y, size_t x);
  virtual ~Map() {}

  MapObject *get(size_t y, size_t x);
  size_t getHeight() const;
  size_t getWidth() const;

  void addObjectToPosition(std::unique_ptr<MapObject> m, size_t y, size_t x);
  void removeObjectFromPosition(size_t y, size_t x);
};

} // namespace Pathos

#endif // PATHOS_MAP
