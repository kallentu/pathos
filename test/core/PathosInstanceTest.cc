#include "core/PathosInstance.h"
#include "controller/mocks/MockNcursesController.h"
#include "mode/mocks/MockMode.h"
#include <gtest/gtest.h>

using namespace Pathos;
using ::testing::AtLeast;

const size_t kStartY = 1;
const size_t kStartX = 1;
const size_t kActionableStartY = 2;
const size_t kActionableStartX = 1;
const size_t kPositiveX = 5;
const size_t kPositiveY = 3;

TEST(PathosInstanceTest, GetPlayerNotNull) {
  PathosInstance inst;
  Player *player = inst.getPlayer();

  ASSERT_NE(player, nullptr);
}

TEST(PathosInstanceTest, GetViewNotNull) {
  PathosInstance inst;
  NcursesView *view = inst.getView();

  ASSERT_NE(view, nullptr);
}

TEST(PathosInstanceTest, GetControllerNotNull) {
  PathosInstance inst;
  NcursesController *contr = inst.getController();

  ASSERT_NE(contr, nullptr);
}

TEST(PathosInstanceTest, SetControllerMock) {
  PathosInstance inst;
  std::unique_ptr<MockNcursesController> contr =
      std::make_unique<MockNcursesController>();
  MockNcursesController *contrPtr = contr.get();

  inst.setController(std::move(contr));

  EXPECT_EQ(inst.getController(), contrPtr);
}

TEST(PathosInstanceTest, GetPositionNotNull) {
  PathosInstance inst;
  Position *startingPos = inst.getPosition();

  ASSERT_NE(startingPos, nullptr);
}

TEST(PathosInstanceTest, GetPositionStartingTopLeft) {
  PathosInstance inst;
  Position *startingPos = inst.getPosition();

  EXPECT_EQ(startingPos->x, kStartX);
  EXPECT_EQ(startingPos->y, kStartY);
}

TEST(PathosInstanceTest, SetPositionNewPointer) {
  PathosInstance inst;

  inst.setPosition(std::make_unique<Position>(kPositiveY, kPositiveX));
  Position *pos = inst.getPosition();

  EXPECT_EQ(pos->x, kPositiveX);
  EXPECT_EQ(pos->y, kPositiveY);
}

TEST(PathosInstanceTest, SetPositionNewCoordinates) {
  PathosInstance inst;

  inst.setPosition(kPositiveY, kPositiveX);
  Position *pos = inst.getPosition();

  EXPECT_EQ(pos->x, kPositiveX);
  EXPECT_EQ(pos->y, kPositiveY);
}

TEST(PathosInstanceTest, GetActionablePositionNotNull) {
  PathosInstance inst;
  Position *actionPos = inst.getActionablePosition();

  ASSERT_NE(actionPos, nullptr);
}

TEST(PathosInstanceTest, SetActionablePositionStarting) {
  PathosInstance inst;
  Position *actionPos = inst.getActionablePosition();

  EXPECT_EQ(actionPos->x, kActionableStartX);
  EXPECT_EQ(actionPos->y, kActionableStartY);
}

TEST(PathosInstanceTest, SetActionablePositionNewPointer) {
  PathosInstance inst;

  inst.setActionablePosition(
      std::make_unique<Position>(kPositiveY, kPositiveX));
  Position *pos = inst.getActionablePosition();

  EXPECT_EQ(pos->x, kPositiveX);
  EXPECT_EQ(pos->y, kPositiveY);
}

TEST(PathosInstanceTest, SetActionablePositionNewCoordinates) {
  PathosInstance inst;

  inst.setActionablePosition(kPositiveY, kPositiveX);
  Position *pos = inst.getActionablePosition();

  EXPECT_EQ(pos->x, kPositiveX);
  EXPECT_EQ(pos->y, kPositiveY);
}

TEST(PathosInstanceTest, GetMapNotNull) {
  PathosInstance inst;
  Map *map = inst.getMap();

  ASSERT_NE(map, nullptr);
}

TEST(PathosInstanceTest, getActiveModeNull) {
  PathosInstance inst;
  const Mode *mode = inst.getActiveMode();

  ASSERT_EQ(mode, nullptr);
}

TEST(PathosInstanceTest, runModeMockModeController) {
  PathosInstance inst;
  std::unique_ptr<MockMode> mockMode = std::make_unique<MockMode>(&inst);
  std::unique_ptr<MockNcursesController> mockController =
      std::make_unique<MockNcursesController>();
  MockMode *modePtr = mockMode.get();
  MockNcursesController *controllerPtr = mockController.get();

  EXPECT_CALL(*modePtr, getHandler()).Times(AtLeast(2));
  EXPECT_CALL(*(static_cast<MockModeHandler *>(modePtr->getHandler())),
              handle(_))
      .Times(AtLeast(1));
  EXPECT_CALL(*controllerPtr, getInput()).Times(AtLeast(1));

  inst.setController(std::move(mockController));
  inst.runMode(std::move(mockMode));
}
