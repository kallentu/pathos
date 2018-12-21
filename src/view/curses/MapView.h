#ifndef PATHOS_MAP_VIEW
#define PATHOS_MAP_VIEW

#include <vector>

#include "view/curses/NcursesView.h"

namespace Pathos {

class MapRequest;
class NotificationRequest;
class NcursesInstance;

class MapView : public NcursesView {
  std::vector<std::vector<char>> map;
  size_t height, width;

public:
  MapView(NcursesInstance *curses);

  void draw(const MapRequest &req) override;
  void draw(const NotificationRequest &req) override;
};

} // namespace Pathos

#endif // PATHOS_MAP_VIEW
