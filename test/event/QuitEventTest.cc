#include "event/QuitEvent.h"
#include "core/PathosInstance.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(QuitEventTest, BeginStopGame) {
  QuitEvent event;
  PathosInstance inst;
  bool initialContinueGame = inst.willContinueGame();

  event.begin(&inst);

  EXPECT_FALSE(inst.willContinueGame());
  EXPECT_TRUE(initialContinueGame);
}

// Just to ensure that there is no switch or anything.
// Once we quit, we quit and it won't be changed back with another event.
TEST(QuitEventTest, BeginStopGameTwice) {
  QuitEvent event;
  PathosInstance inst;

  event.begin(&inst);
  event.begin(&inst);

  EXPECT_FALSE(inst.willContinueGame());
}
