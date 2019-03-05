#ifndef PATHOS_MAP_REQUEST
#define PATHOS_MAP_REQUEST

#include "core/Position.h"
#include "request/ViewRequest.h"
#include <vector>

namespace Pathos {

class Map;

// A request to change the current map.
struct MapRequest : public ViewRequest {
  Map *map;
  Position *playerPos;

  MapRequest(Map *m, Position *playerPos);
  void beDrawnBy(View &view) const override;
};

} // namespace Pathos

#endif // PATHOS_MAP_REQUEST
