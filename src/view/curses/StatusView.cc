#include "view/curses/StatusView.h"
#include "quest/Quest.h"
#include "request/ClearQuickStatusRequest.h"
#include "request/ClearTalkRequest.h"
#include "request/NotificationRequest.h"
#include "request/QuestRequest.h"
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

  // Prints on the last-ish line of the screen.
  QUICK_STATUS_X = width - STATUS_WIDTH;
  QUICK_STATUS_Y = height - 3;
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
  size_t y = height * 1 / 3;
  size_t dialoguePos = 0;
  size_t dialogueLength = STATUS_WIDTH - 1;

  // Leave two lines for bottom lines changes (ie. quests ...)
  while (y < QUICK_STATUS_Y && dialoguePos < dialogue.length()) {
    // Take string that fits, print.
    std::string dialogueSubstr = dialogue.substr(dialoguePos, dialogueLength);

    NcursesView::getInstance()->clearLine(y, x);
    NcursesView::getInstance()->movePrint(y, x, dialogueSubstr);

    dialoguePos += dialogueLength;
    ++y;
  }

  NcursesViewDecorator::view->draw(req);
}

void StatusView::draw(const QuestRequest &req) {
  // Quick status change to quest options.
  std::string questOptions;
  switch (req.status) {
    case Quest::Status::NotStarted:
      questOptions = "Accept (a) Decline (d)";
      break;
    case Quest::Status::InProgress:
      questOptions = "Continue... (a)";
      break;
    default:
      return;
  }

  NcursesView::getInstance()->movePrint(QUICK_STATUS_Y, QUICK_STATUS_X,
                                        questOptions);

  // Change dialogue for quest status specifically.
  TalkRequest dialogueReq =
      TalkRequest(req.getQuest()->getDialogue(req.status));
  draw(dialogueReq);
}

void StatusView::draw(const CombatRequest &req) {
  (void) req;
  // TODO: Health, attack, mob health, mob attack
  // TODO: Display all attacks and options based on state.
}

void StatusView::draw(const ClearQuickStatusRequest &req) {
  (void) req; // Don't actually use it
  NcursesView::getInstance()->clearLine(QUICK_STATUS_Y, QUICK_STATUS_X);
}

void StatusView::draw(const ClearTalkRequest &req) {
  (void) req; // Don't actually use it

  size_t x = width - STATUS_WIDTH;
  size_t y = height * 1 / 3;

  while (y < QUICK_STATUS_Y) {
    NcursesView::getInstance()->clearLine(y, x);
    ++y;
  }
}
