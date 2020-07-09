#include "quest/athens/KillWolvesQuest.h"
#include "mob/friendly/quest/mocks/MockQuestGiver.h"
#include "state/Stats.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(KillWolvesQuestTest, AllDialogueNonNull) {
  MockQuestGiver questGiver;
  KillWolvesQuest quest = KillWolvesQuest(&questGiver);

  EXPECT_FALSE(quest.getDialogue(Quest::Status::NotStarted).empty());
  EXPECT_FALSE(quest.getDialogue(Quest::Status::InProgress).empty());
  EXPECT_FALSE(quest.getDialogue(Quest::Status::Completed).empty());
}

TEST(KillWolvesQuestTest,
     CheckConditionsNotStartedSetInitialCountChangeStatus) {
  MockQuestGiver questGiver;
  PathosInstance inst;
  KillWolvesQuest quest = KillWolvesQuest(&questGiver);

  // Set initial kill count to 2
  Stats::instance()->setWolvesKilled(2);
  Quest::Status oldStatus = quest.getStatus();
  Quest::Status newStatus = quest.checkConditions(&inst);

  EXPECT_EQ(oldStatus, Quest::Status::NotStarted);
  EXPECT_EQ(newStatus, Quest::Status::InProgress);
  EXPECT_EQ(quest.getInitialKillCount(), 2);
}

TEST(KillWolvesQuestTest, CheckConditionsInProgressNotEnoughKills) {
  MockQuestGiver questGiver;
  PathosInstance inst;
  KillWolvesQuest quest = KillWolvesQuest(&questGiver);

  Stats::instance()->setWolvesKilled(2);
  Quest::Status oldStatus = quest.checkConditions(&inst);

  Stats::instance()->setWolvesKilled(12);
  Quest::Status newStatus = quest.checkConditions(&inst);

  EXPECT_EQ(oldStatus, Quest::Status::InProgress);
  EXPECT_EQ(newStatus, Quest::Status::InProgress);
  EXPECT_EQ(quest.getInitialKillCount(), 2);
}

TEST(KillWolvesQuestTest, CheckConditionsInProgress20KillsChangeStatus) {
  MockQuestGiver questGiver;
  PathosInstance inst;
  KillWolvesQuest quest = KillWolvesQuest(&questGiver);

  Stats::instance()->setWolvesKilled(2);
  Quest::Status oldStatus = quest.checkConditions(&inst);

  Stats::instance()->setWolvesKilled(24);
  Quest::Status newStatus = quest.checkConditions(&inst);

  EXPECT_EQ(oldStatus, Quest::Status::InProgress);
  EXPECT_EQ(newStatus, Quest::Status::Completed);
}

TEST(KillWolvesQuestTest, CheckConditionsCompletedNoStatusChange) {
  MockQuestGiver questGiver;
  PathosInstance inst;
  KillWolvesQuest quest = KillWolvesQuest(&questGiver);

  Stats::instance()->setWolvesKilled(70);
  Quest::Status status = quest.checkConditions(&inst);

  EXPECT_EQ(status, Quest::Status::Completed);

  Stats::instance()->setWolvesKilled(71);
  Quest::Status newStatus = quest.checkConditions(&inst);

  EXPECT_EQ(newStatus, Quest::Status::Completed);
}
