#include "map/Map.h"
#include "map/Ground.h"
#include "map/MapObject.h"
#include "map/Wall.h"
#include "view/curses/MapView.h"
#include <memory>
#include <vector>

using namespace Pathos;

Map::Map(size_t y, size_t x) {
  // Walls added for the corners of the map
  // Initial fill with default MapObjects (ground)
  for (size_t i = 0; i < y; i++) {
    std::vector<std::unique_ptr<MapObject>> row;

    for (size_t j = 0; j < x; j++) {
      // Top or bottom row
      // Start or end of row
      if (i == 0 || i == y - 1 || j == 0 || j == x - 1) {
        row.push_back(std::make_unique<Wall>());
      } else {
        row.push_back(std::make_unique<Ground>());
      }
    }

    map.push_back(std::move(row));
  }
}

MapObject *Map::get(size_t y, size_t x) { return map[y][x].get(); }

void Map::addObjectToPosition(std::unique_ptr<MapObject> m, size_t y,
                              size_t x) {
  map[y][x].reset();
  map[y][x] = std::move(m);
}

void Map::removeObjectFromPosition(size_t y, size_t x) {
  map[y][x].reset();
  map[y][x] = std::make_unique<Ground>();
}
