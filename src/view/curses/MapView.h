#ifndef PATHOS_MAP_VIEW
#define PATHOS_MAP_VIEW

#include "map/Map.h"
#include "view/curses/NcursesView.h"
#include <memory>

namespace Pathos {

class MapRequest;
class StatusRequest;
class NotificationRequest;
class NcursesInstance;

class MapView : public NcursesView {
  // TODO: Make the MapManager own the map instead of the MapView
  size_t height, width;
  Map *map;

public:
  MapView(NcursesInstance *curses);

  Map *getMap() const { return map; }
  size_t getHeight() const { return height; }
  size_t getWidth() const { return width; }

  void setHeight(size_t h) { height = h; }
  void setWidth(size_t w) { width = w; }

  // Prints the Map from the MapRequest using ncurses.
  void draw(const MapRequest &req) override;

  // Does not print anything for StatusRequest.
  void draw(const StatusRequest &req) override;

  // Does not print anything for NotificationRequest.
  void draw(const NotificationRequest &req) override;

private:
  void redrawMap();
};

} // namespace Pathos

#endif // PATHOS_MAP_VIEW
