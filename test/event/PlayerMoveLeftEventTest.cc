#include "core/PathosInstance.h"
#include "event/PlayerMoveLeftEvent.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(PlayerMoveLeftEventTest, BeginGroundPositionChange) {
  PlayerMoveLeftEvent event;
  PathosInstance inst;
  inst.setPosition(1, 2);

  event.begin(&inst);

  EXPECT_EQ(inst.getPosition()->x, 1);
  EXPECT_EQ(inst.getPosition()->y, 1);
}

TEST(PlayerMoveLeftEventTest, BeginOutOfBoundsNoPositionChange) {
  PlayerMoveLeftEvent event;
  PathosInstance inst;
  inst.setPosition(1, 1);

  event.begin(&inst);

  EXPECT_EQ(inst.getPosition()->x, 1);
  EXPECT_EQ(inst.getPosition()->y, 1);
}

TEST(PlayerMoveLeftEventTest, BeginActionablePositionMoved) {
  PlayerMoveLeftEvent event;
  PathosInstance inst;
  inst.setPosition(1, 1);

  event.begin(&inst);

  EXPECT_EQ(inst.getActionablePosition()->x, 0);
  EXPECT_EQ(inst.getActionablePosition()->y, 1);
}
