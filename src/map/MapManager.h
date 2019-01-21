#ifndef PATHOS_MAP_MANAGER
#define PATHOS_MAP_MANAGER

#include "map/Map.h"
#include <memory>
#include <vector>

namespace Pathos {

// Manages all the maps and switches between each once player moves.
class MapManager final {
  std::vector<std::unique_ptr<Map>> maps;
  Map *activeMap;

public:
  // TODO: Initialize and populate with all maps.
  MapManager() {}

  // TODO: Find a way to search for a map.
  Map *getActiveMap() const { return activeMap; }
};

} // namespace Pathos

#endif // PATHOS_MAP_MANAGER
