#include "core/PathosInstance.h"
#include "event/PlayerMoveDownEvent.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(PlayerMoveDownEventTest, BeginGroundPositionChange) {
  PlayerMoveDownEvent event;
  PathosInstance inst;
  inst.setPosition(1, 1);

  event.begin(&inst);

  EXPECT_EQ(inst.getPosition()->x, 1);
  EXPECT_EQ(inst.getPosition()->y, 2);
}

TEST(PlayerMoveDownEventTest, BeginOutOfBoundsNoPositionChange) {
  PlayerMoveDownEvent event;
  PathosInstance inst;
  inst.setPosition(99, 1);

  event.begin(&inst);

  EXPECT_EQ(inst.getPosition()->x, 1);
  EXPECT_EQ(inst.getPosition()->y, 99);
}

TEST(PlayerMoveDownEventTest, BeginActionablePositionMoved) {
  PlayerMoveDownEvent event;
  PathosInstance inst;
  inst.setPosition(99, 1);

  event.begin(&inst);

  EXPECT_EQ(inst.getActionablePosition()->x, 1);
  EXPECT_EQ(inst.getActionablePosition()->y, 100);
}
