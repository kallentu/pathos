#include "map/Map.h"
#include "map/Ground.h"
#include "map/MapObject.h"
#include "map/Wall.h"
#include "view/curses/MapView.h"
#include <memory>
#include <vector>

using namespace Pathos;

Map::Map(MapView *v) {
  size_t y = v->getHeight();
  size_t x = v->getWidth();

  // Walls added for the corners of the map
  // Initial fill with default MapObjects (ground)
  for (size_t i = 0; i < y; i++) {
    std::vector<std::unique_ptr<MapObject>> row;

    for (size_t j = 0; j < x; j++) {
      // Top or bottom row
      // Start or end of row
      if (i == 0 || i == y - 1 || j == 0 || j == x - 1) {
        row[j] = std::make_unique<Wall>();
      } else {
        row[j] = std::make_unique<Ground>();
      }
    }

    map[i] = std::move(row);
  }
}

void Map::addObjectToPosition(std::unique_ptr<MapObject> m, size_t y,
                              size_t x) {}

void Map::removeObjectFromPosition(size_t y, size_t x) {}
