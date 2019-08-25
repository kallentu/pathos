#include "mode/handler/QuestModeHandler.h"
#include "controller/Char.h"
#include "event/CheckVicinityEvent.h"
#include "event/LeaveModeEvent.h"
#include "quest/mocks/MockQuest.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(QuestModeHandlerTest, NotStartedAcceptQuestCheckVicinityEvent) {
  MockQuest quest = MockQuest(nullptr);
  QuestModeHandler handler = QuestModeHandler(&quest);

  quest.setStatus(Quest::Status::NotStarted);
  std::unique_ptr<Event> event = handler.handle(Char(97));

  EXPECT_NE(dynamic_cast<CheckVicinityEvent *>(event.get()), nullptr);
  EXPECT_EQ(quest.getStatus(), Quest::Status::InProgress);
}

TEST(QuestModeHandlerTest, NotStartedDeclineQuestLeaveModeEvent) {
  MockQuest quest = MockQuest(nullptr);
  QuestModeHandler handler = QuestModeHandler(&quest);

  quest.setStatus(Quest::Status::NotStarted);
  std::unique_ptr<Event> event = handler.handle(Char(100));

  EXPECT_NE(dynamic_cast<LeaveModeEvent *>(event.get()), nullptr);
  EXPECT_EQ(quest.getStatus(), Quest::Status::NotStarted);
}

TEST(QuestModeHandlerTest, InProgressAcceptQuestLeaveModeEvent) {
  MockQuest quest = MockQuest(nullptr);
  QuestModeHandler handler = QuestModeHandler(&quest);

  quest.setStatus(Quest::Status::InProgress);
  std::unique_ptr<Event> event = handler.handle(Char(97));

  EXPECT_NE(dynamic_cast<LeaveModeEvent *>(event.get()), nullptr);
  EXPECT_EQ(quest.getStatus(), Quest::Status::InProgress);
}

TEST(QuestModeHandlerTest, CompletedAnyKeyLeaveModeEvent) {
  MockQuest quest = MockQuest(nullptr);
  QuestModeHandler handler = QuestModeHandler(&quest);

  quest.setStatus(Quest::Status::Completed);
  std::unique_ptr<Event> event = handler.handle(Char(97));

  EXPECT_NE(dynamic_cast<LeaveModeEvent *>(event.get()), nullptr);
  EXPECT_EQ(quest.getStatus(), Quest::Status::Completed);
}

TEST(QuestModeHandlerTest, NotCompletedQuestBadInputNullPtr) {
  MockQuest quest = MockQuest(nullptr);
  QuestModeHandler handler = QuestModeHandler(&quest);

  quest.setStatus(Quest::Status::NotStarted);
  std::unique_ptr<Event> notStartedEvent = handler.handle(Char(98));

  quest.setStatus(Quest::Status::InProgress);
  std::unique_ptr<Event> inProgressEvent = handler.handle(Char(98));

  EXPECT_EQ(notStartedEvent, nullptr);
  EXPECT_EQ(inProgressEvent, nullptr);
}
