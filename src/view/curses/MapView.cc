#include "view/curses/MapView.h"
#include "map/Map.h"
#include "map/MapObject.h"
#include "request/MapRequest.h"
#include "view/curses/NcursesInstance.h"
#include "view/curses/NcursesView.h"
#include <memory>
#include <ncurses.h>

using namespace Pathos;

MapView::MapView(NcursesInstance *curses)
    : NcursesView(curses), height{NcursesView::getHeight()},
      width{NcursesView::getWidth()} {}

// TODO: Set the map to a certain size.and move it accordingly.
void MapView::draw(const MapRequest &req) {
  map = req.map;
  redrawMap();
}

void MapView::draw(const StatusRequest &req) {
  (void)req;
  redrawMap();
}

void MapView::draw(const NotificationRequest &req) {
  (void)req;
  redrawMap();
}

void MapView::redrawMap() {
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      MapObject *m = map->get(i, j);

      // Convert Char to correctly printed symbol
      switch (m->getCharType()) {
      case MapObject::Char::At:
        // Player
        NcursesView::getInstance()->movePrint(i, j, "@");
        break;
      case MapObject::Char::Lantern:
        // Hostile
        NcursesView::getInstance()->moveAddChar(i, j, ACS_LANTERN);
        break;
      case MapObject::Char::Sterling:
        // Friendly
        NcursesView::getInstance()->moveAddChar(i, j, ACS_STERLING);
        break;
      case MapObject::Char::Bound:
        // Wall
        if (i == 0 && j == 0) {
          // Upper left corner
          NcursesView::getInstance()->moveAddChar(i, j, ACS_ULCORNER);
        } else if (i == height - 1 && j == 0) {
          // Lower left corner
          NcursesView::getInstance()->moveAddChar(i, j, ACS_LLCORNER);
        } else if (i == 0 && j == width - 1) {
          // Upper right corner
          NcursesView::getInstance()->moveAddChar(i, j, ACS_URCORNER);
        } else if (i == height - 1 && j == width - 1) {
          // Lower right corner
          NcursesView::getInstance()->moveAddChar(i, j, ACS_LRCORNER);
        } else if (i == 0 || i == height - 1) {
          // Top/bottom bounds
          NcursesView::getInstance()->moveAddChar(i, j, ACS_HLINE);
        } else if (j == 0 || j == width - 1) {
          // Left/right bounds
          NcursesView::getInstance()->moveAddChar(i, j, ACS_VLINE);
        }
        break;
      case MapObject::Char::Empty:
        // Ground
        NcursesView::getInstance()->movePrint(i, j, " ");
        break;
      default:
        // Unrecognized Char type.
        break;
      }
    }
  }
}
