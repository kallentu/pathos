#include "request/MapRequest.h"
#include "map/Map.h"
#include "view/View.h"

using namespace Pathos;

// TODO: Complete after Map

MapRequest::MapRequest(Map *m) {}

MapRequest::~MapRequest() {}

void MapRequest::beDrawnBy(View &view) const { view.draw(*this); }

void MapRequest::convertMap(Map *m) {}
