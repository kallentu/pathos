#include "event/MultipleEvent.h"
#include "core/PathosInstance.h"
#include "event/mocks/MockEvent.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(MultipleEventTest, BeginNoEventsNoExceptionThrown) {
  MultipleEvent event;
  PathosInstance inst;

  event.begin(&inst);
}

TEST(MultipleEventTest, BeginMultipleEvents) {
  MultipleEvent event;
  PathosInstance inst;
  std::unique_ptr<MockEvent> e1 = std::make_unique<MockEvent>();
  std::unique_ptr<MockEvent> e2 = std::make_unique<MockEvent>();
  std::unique_ptr<MockEvent> e3 = std::make_unique<MockEvent>();
  MockEvent *event1 = e1.get();
  MockEvent *event2 = e2.get();
  MockEvent *event3 = e3.get();

  EXPECT_CALL(*event1, begin(_)).Times(1);
  EXPECT_CALL(*event2, begin(_)).Times(1);
  EXPECT_CALL(*event3, begin(_)).Times(1);

  event.addEvent(std::move(e1));
  event.addEvent(std::move(e2));
  event.addEvent(std::move(e3));
  event.begin(&inst);
}
