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

void MapView::draw(const MapRequest &req) {
  map = req.map;
  playerPos = req.playerPos;
  drawMap();
}

void MapView::draw(const StatusRequest &req) {
  (void)req;
  drawMap();
}

void MapView::draw(const NotificationRequest &req) {
  (void)req;
  drawMap();
}

void MapView::draw(const TalkRequest &req) {
  (void)req;
  drawMap();
}

void MapView::drawMap() {
  // Initial starting positions, work off these to calculate which MapObject.
  size_t mapYStart = getMapYStart();
  size_t mapXStart = getMapXStart();

  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {

      // Current map object, different from position on screen.
      size_t mapY = mapYStart + i;
      size_t mapX = mapXStart + j;

      MapObject *m = map->get(mapY, mapX);

      // Convert Char to correctly printed symbol
      switch (m->getCharType()) {
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

  // Player drawn on top of the already drawn map.
  drawPlayer(mapYStart, mapXStart);
}

void MapView::drawPlayer() { drawPlayer(0, 0); }

void MapView::drawPlayer(size_t mapYStart, size_t mapXStart) {
  // If has a shifted map start, will take into account and draw Player
  // accordingly.
  NcursesView::getInstance()->movePrint(playerPos->y - mapYStart,
                                        playerPos->x - mapXStart, "@");
}

size_t MapView::getMapYStart() const {
  size_t playerY = playerPos->y;

  if (playerY < height / 2) {
    // Player is at top of map, draw from top.
    return 0;
  } else if (playerY >= map->getHeight() - height / 2) {
    // Player is at bottom of map, draw from bottom with difference.
    return map->getHeight() - height;
  }

  // Otherwise, center player in map.
  return playerY - height / 2;
}

size_t MapView::getMapXStart() const {
  size_t playerX = playerPos->x;

  if (playerX < width / 2) {
    // Player is at left-most of the map, draw from left.
    return 0;
  } else if (playerX > map->getWidth() - width / 2) {
    // Player is at right-most of the map, draw from right.
    return map->getWidth() - width;
  }

  // Otherwise, center player in map.
  return playerX - width / 2;
}
