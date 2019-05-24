#include "map/AthensMap.h"
#include "map/Map.h"
#include "mob/friendly/quest/Gaia.h"

using namespace Pathos;

AthensMap::AthensMap() : Map(100, 100) {
  Map::addObjectToPosition(std::make_unique<Gaia>(), 25, 25);
}
