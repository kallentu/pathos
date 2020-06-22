#include "view/curses/StatusView.h"
#include "quest/Quest.h"
#include "mob/player/Player.h"
#include "request/ClearQuickStatusRequest.h"
#include "request/ClearMainStatusRequest.h"
#include "request/CombatRequest.h"
#include "request/NotificationRequest.h"
#include "request/QuestRequest.h"
#include "request/StatusRequest.h"
#include "state/Status.h"
#include "view/curses/NcursesInstance.h"
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

void StatusView::draw(const StatusRequest &req) {
  size_t marginLeft = width - STATUS_WIDTH;
  NcursesView::getInstance()->movePrint(0, marginLeft, req.status->playerName);
  NcursesView::getInstance()->movePrint(1, marginLeft, "Level: " + std::to_string(req.status->playerLevel) + "  " +
                                                       std::to_string(req.status->playerDrachma) + "d");
  NcursesView::getInstance()->movePrint(2, marginLeft,
                                        "Experience: " + std::to_string(req.status->playerExperience) + "/" +
                                        std::to_string(req.status->playerExperienceThreshold));
  NcursesView::getInstance()->movePrint(
      3, marginLeft,
      "Health: " + std::to_string(req.status->playerHealth) + "/" + std::to_string(req.status->playerMaxHealth));
  NcursesView::getInstance()->movePrint(
      4, marginLeft, "Physical Damage: " + std::to_string(req.status->playerPhysicalDamage));
  NcursesView::getInstance()->movePrint(
      5, marginLeft, "Magic Damage: " + std::to_string(req.status->playerMagicDamage));
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
    case Quest::Status::Completed:
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
  // TODO: Display all attacks and options based on state.

  // X starts on the edge of the width
  size_t x = width - STATUS_WIDTH;
  size_t y = height * 1 / 4;


  if (!req.hostile->isDeceased()) {
    NcursesView::getInstance()->clearLine(y, x);
    NcursesView::getInstance()->movePrint(y++, x,
                                          req.hostile->getName() + " " + std::to_string(req.hostile->getHealth()) +
                                          "/" + std::to_string(req.hostile->getMaxHealth()));
    NcursesView::getInstance()->clearLine(y, x);
    NcursesView::getInstance()->movePrint(y++, x,
                                          "PA: " + std::to_string(req.hostile->getPhysicalDamage()) + " MA:" +
                                          std::to_string(req.hostile->getMagicDamage()));
  } else {
    // Simply clear the hostile status lines when they die.
    NcursesView::getInstance()->clearLine(y++, x);
    NcursesView::getInstance()->clearLine(y++, x);
  }

  NcursesView::getInstance()->clearLine(y, x);
  NcursesView::getInstance()->movePrint(y, x, req.log->description);

  NcursesViewDecorator::view->draw(req);
}

void StatusView::draw(const ClearQuickStatusRequest &req) {
  (void) req; // Don't actually use it
  NcursesView::getInstance()->clearLine(QUICK_STATUS_Y, QUICK_STATUS_X);
}

void StatusView::draw(const ClearMainStatusRequest &req) {
  (void) req; // Don't actually use it

  size_t x = width - STATUS_WIDTH;
  size_t y = height * 1 / 4;

  while (y < QUICK_STATUS_Y) {
    NcursesView::getInstance()->clearLine(y, x);
    ++y;
  }
}
