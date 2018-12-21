#ifndef PATHOS_MAP_REQUEST
#define PATHOS_MAP_REQUEST

#include <vector>

#include "request/ViewRequest.h"

namespace Pathos {

class Map;

struct MapRequest : public ViewRequest {
  std::vector<std::vector<char>> map;

  MapRequest(Map *m);
  ~MapRequest();

  void beDrawnBy(View &view) const override;

private:
  void convertMap(Map *m);
};

} // namespace Pathos

#endif // PATHOS_MAP_REQUEST
