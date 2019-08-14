#include "core/PathosInstance.h"
#include "event/PlayerMoveUpEvent.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(PlayerMoveUpEventTest, BeginGroundPositionChange) {
  PlayerMoveUpEvent event;
  PathosInstance inst;
  inst.setPosition(2, 1);

  event.begin(&inst);

  EXPECT_EQ(inst.getPosition()->x, 1);
  EXPECT_EQ(inst.getPosition()->y, 1);
}

TEST(PlayerMoveUpEventTest, BeginOutOfBoundsNoPositionChange) {
  PlayerMoveUpEvent event;
  PathosInstance inst;
  inst.setPosition(1, 1);

  event.begin(&inst);

  EXPECT_EQ(inst.getPosition()->x, 1);
  EXPECT_EQ(inst.getPosition()->y, 1);
}

TEST(PlayerMoveUpEventTest, BeginActionablePositionMoved) {
  PlayerMoveUpEvent event;
  PathosInstance inst;
  inst.setPosition(1, 1);

  event.begin(&inst);

  EXPECT_EQ(inst.getActionablePosition()->x, 1);
  EXPECT_EQ(inst.getActionablePosition()->y, 0);
}
