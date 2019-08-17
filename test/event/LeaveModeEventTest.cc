#include "event/LeaveModeEvent.h"
#include "core/mocks/MockPathosInstance.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(LeaveModeEventTest, BeginLeaveMode) {
  LeaveModeEvent event;
  MockPathosInstance inst;
  int leaveRequests = inst.getLeaveModeRequests();

  event.begin(&inst);

  EXPECT_EQ(inst.getLeaveModeRequests(), leaveRequests + 1);
}
