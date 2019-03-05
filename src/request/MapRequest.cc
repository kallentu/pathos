#include "request/MapRequest.h"
#include "core/Position.h"
#include "map/Map.h"
#include "view/View.h"

using namespace Pathos;

MapRequest::MapRequest(Map *m, Position *playerPos)
    : map{m}, playerPos{playerPos} {}

void MapRequest::beDrawnBy(View &view) const { view.draw(*this); }
