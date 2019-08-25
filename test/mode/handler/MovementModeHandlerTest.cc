#include "mode/handler/MovementModeHandler.h"
#include "controller/Char.h"
#include "event/CheckVicinityEvent.h"
#include "event/MultipleEvent.h"
#include "event/QuitEvent.h"
#include <gtest/gtest.h>
#include <ncurses.h>

using namespace Pathos;

TEST(MovementModeHandlerTest, UpArrowReturnEvent) {
  MovementModeHandler handler;
  std::unique_ptr<Event> event = handler.handle(Char(KEY_UP));

  EXPECT_NE(dynamic_cast<MultipleEvent *>(event.get()), nullptr);
}

TEST(MovementModeHandlerTest, DownArrowReturnEvent) {
  MovementModeHandler handler;
  std::unique_ptr<Event> event = handler.handle(Char(KEY_DOWN));

  EXPECT_NE(dynamic_cast<MultipleEvent *>(event.get()), nullptr);
}

TEST(MovementModeHandlerTest, RightArrowReturnEvent) {
  MovementModeHandler handler;
  std::unique_ptr<Event> event = handler.handle(Char(KEY_RIGHT));

  EXPECT_NE(dynamic_cast<MultipleEvent *>(event.get()), nullptr);
}

TEST(MovementModeHandlerTest, LeftArrowReturnEvent) {
  MovementModeHandler handler;
  std::unique_ptr<Event> event = handler.handle(Char(KEY_LEFT));

  EXPECT_NE(dynamic_cast<MultipleEvent *>(event.get()), nullptr);
}

TEST(MovementModeHandlerTest, CtrlCReturnQuitEvent) {
  MovementModeHandler handler;
  std::unique_ptr<Event> event = handler.handle(Char(0x03));

  EXPECT_NE(dynamic_cast<QuitEvent *>(event.get()), nullptr);
}

TEST(MovementModeHandlerTest, SpaceReturnQuitEvent) {
  MovementModeHandler handler;
  std::unique_ptr<Event> event = handler.handle(Char(0x20));

  EXPECT_NE(dynamic_cast<CheckVicinityEvent *>(event.get()), nullptr);
}
