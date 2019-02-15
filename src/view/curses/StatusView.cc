#include "view/curses/StatusView.h"
#include "request/StatusRequest.h"
#include "request/TalkRequest.h"
#include "state/Status.h"
#include "view/curses/NcursesInstance.h"
#include "view/curses/NcursesView.h"
#include "view/curses/NcursesViewDecorator.h"
#include <string>

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

void StatusView::draw(const TalkRequest &req) {
  std::string dialogue = req.npcDialogue;

  // X starts on the edge of the width
  size_t x = width - STATUS_WIDTH;
  // Y starts 2/3 of the screen down. Most of the room left for Status.
  size_t y = height * 2 / 3;
  size_t dialoguePos = 0;
  size_t dialogueLength = width - 1;

  while (y < height && dialoguePos < dialogue.length()) {
    // Take string that fits, print.
    std::string dialogueSubstr = dialogue.substr(dialoguePos, dialogueLength);
    NcursesView::getInstance()->movePrint(y, x, dialogueSubstr);
    dialoguePos += dialogueLength + 1;
    dialogue = dialogue.substr(dialoguePos);
    ++y;
  }

  NcursesViewDecorator::view->draw(req);
}
