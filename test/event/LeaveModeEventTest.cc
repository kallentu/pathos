#include "event/LeaveModeEvent.h"
#include "core/mocks/MockPathosInstance.h"
#include "mode/mocks/MockMode.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(LeaveModeEventTest, BeginLeaveMode) {
  LeaveModeEvent event;
  MockPathosInstance inst;
  int leaveRequests = inst.getLeaveModeRequests();

  event.begin(&inst);

  EXPECT_EQ(inst.getLeaveModeRequests(), leaveRequests + 1);
}

TEST(LeaveModeEventTest, BeginRunMode) {
  LeaveModeEvent event;
  MockPathosInstance inst;
  int leaveRequests = inst.getLeaveModeRequests();

  event.begin(&inst);

  // Mode left, will revert to previous leaveRequests
  EXPECT_CALL(inst, run()).Times(1);
  inst.runMode(std::make_unique<MockMode>(&inst));

  EXPECT_EQ(inst.getLeaveModeRequests(), leaveRequests);
}
