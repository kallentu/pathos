#include "request/MapRequest.h"
#include "map/Map.h"
#include "view/View.h"

using namespace Pathos;

MapRequest::MapRequest(Map *m) : map{m} {}

void MapRequest::beDrawnBy(View &view) const { view.draw(*this); }
