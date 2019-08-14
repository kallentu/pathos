#include "core/PathosInstance.h"
#include "event/PlayerMoveRightEvent.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(PlayerMoveRightEventTest, BeginGroundPositionChange) {
  PlayerMoveRightEvent event;
  PathosInstance inst;
  inst.setPosition(1, 1);

  event.begin(&inst);

  EXPECT_EQ(inst.getPosition()->x, 2);
  EXPECT_EQ(inst.getPosition()->y, 1);
}

TEST(PlayerMoveRightEventTest, BeginOutOfBoundsNoPositionChange) {
  PlayerMoveRightEvent event;
  PathosInstance inst;
  inst.setPosition(1, 99);

  event.begin(&inst);

  EXPECT_EQ(inst.getPosition()->x, 99);
  EXPECT_EQ(inst.getPosition()->y, 1);
}

TEST(PlayerMoveRightEventTest, BeginActionablePositionMoved) {
  PlayerMoveRightEvent event;
  PathosInstance inst;
  inst.setPosition(1, 99);

  event.begin(&inst);

  EXPECT_EQ(inst.getActionablePosition()->x, 100);
  EXPECT_EQ(inst.getActionablePosition()->y, 1);
}
