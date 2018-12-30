#ifndef PATHOS_MAP_REQUEST
#define PATHOS_MAP_REQUEST

#include <vector>

#include "request/ViewRequest.h"

namespace Pathos {

class Map;

struct MapRequest : public ViewRequest {
  Map *map;

  MapRequest(Map *m);
  ~MapRequest();

  void beDrawnBy(View &view) const override;
};

} // namespace Pathos

#endif // PATHOS_MAP_REQUEST
