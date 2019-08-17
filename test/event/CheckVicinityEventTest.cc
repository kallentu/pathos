#include "event/CheckVicinityEvent.h"
#include "core/PathosInstance.h"
#include "core/mocks/MockPathosInstance.h"
#include "mode/QuestMode.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(CheckVicinityEventTest, BeginNoQuestGiverAround) {
  CheckVicinityEvent event;
  MockPathosInstance inst;

  event.begin(&inst);
}

TEST(CheckVicinityEventTest, BeginQuestGiverAddQuestMode) {
  CheckVicinityEvent event;
  MockPathosInstance inst;
  inst.setActionablePosition(10, 15); // Gaia NPC coordinates

  EXPECT_CALL(inst, run()).Times(1);

  event.begin(&inst);

  EXPECT_NE(dynamic_cast<const QuestMode *>(inst.getActiveMode()), nullptr);
}
