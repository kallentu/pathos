#include "view/curses/MapView.h"
#include "view/curses/NcursesInstance.h"
#include "view/curses/NcursesView.h"

using namespace Pathos;

MapView::MapView(NcursesInstance *curses)
    : NcursesView(curses), height{NcursesView::getHeight()},
      width{NcursesView::getWidth()} {}

void MapView::draw(const MapRequest &req) {}

void MapView::draw(const NotificationRequest &req) {}
