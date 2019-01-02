#include "view/curses/StatusView.h"
#include "request/StatusRequest.h"
#include "state/Status.h"
#include "view/curses/NcursesInstance.h"
#include "view/curses/NcursesView.h"
#include "view/curses/NcursesViewDecorator.h"

using namespace Pathos;

StatusView::StatusView(std::unique_ptr<NcursesView> view)
    : NcursesViewDecorator(std::move(view)) {
  height = NcursesViewDecorator::view->getHeight();
  width = NcursesViewDecorator::view->getWidth();
  NcursesViewDecorator::view->setWidth(width - STATUS_WIDTH);
}

void StatusView::draw(const MapRequest &req) {
  NcursesViewDecorator::view->draw(req);
}

// TODO: deal with status line wrapping
void StatusView::draw(const StatusRequest &req) {
  size_t marginLeft = width - STATUS_WIDTH;
  NcursesView::getInstance()->movePrint(
      0, marginLeft + 1, std::to_string(req.status->playerMaxHealth));
  NcursesView::getInstance()->movePrint(
      1, marginLeft + 1, std::to_string(req.status->playerHealth));
  NcursesViewDecorator::view->draw(req);
}

void StatusView::draw(const NotificationRequest &req) {
  NcursesViewDecorator::view->draw(req);
}
