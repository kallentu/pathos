#include "map/AthensMap.h"
#include "map/Map.h"
#include "mob/friendly/quest/Gaia.h"
#include "mob/hostile/Wolf.h"

using namespace Pathos;

const size_t ATHENS_Y = 40;
const size_t ATHENS_X = 40;

AthensMap::AthensMap() : Map(ATHENS_Y, ATHENS_X) {
  Map::addObjectToPosition(std::make_unique<Gaia>(), 5, 10);
  Map::addObjectToPosition(std::make_unique<Wolf>(), 2, 4);
}
