#ifndef PATHOS_MAP_VIEW
#define PATHOS_MAP_VIEW

#include "map/Map.h"
#include "view/curses/NcursesView.h"
#include <memory>

namespace Pathos {

class MapRequest;
class NotificationRequest;
class NcursesInstance;

class MapView : public NcursesView {
  // TODO: Make the MapManager own the map instead of the MapView
  std::unique_ptr<Map> map;
  size_t height, width;

public:
  MapView(NcursesInstance *curses);

  Map *getMap() const;

  // Prints the Map from the MapRequest using ncurses.
  void draw(const MapRequest &req) override;

  // Does not print anything for NotificationRequest.
  void draw(const NotificationRequest &req) override;
};

} // namespace Pathos

#endif // PATHOS_MAP_VIEW
