#include <gtest/gtest.h>
#include <core/PathosInstance.h>
#include <mob/friendly/quest/Gaia.h>
#include <mob/player/Player.h>
#include <quest/QuestManager.h>
#include <quest/athens/KillWolvesQuest.h>
#include <request/QuestRequest.h>
#include <state/Stats.h>

using namespace Pathos;

std::string GAIA_DIALOGUE = "Be at peace, Periphas... There is so much more to discover and explore in the world.";

TEST(GaiaTest, BeTalkedToByPlayerReturnTalkRequest) {
  Gaia gaia;
  Player player;

  std::unique_ptr<TalkRequest> talkRequest = gaia.beTalkedToBy(player);
  EXPECT_NE(talkRequest, nullptr);
  EXPECT_EQ(talkRequest->npcDialogue, GAIA_DIALOGUE);
}

TEST(GaiaTest, haveQuestRequestRetrievedByInProgressStatus) {
  Gaia gaia;
  QuestManager qm;
  PathosInstance inst;

  std::unique_ptr<QuestRequest> questRequest = gaia.retrieveQuestRequestWithInstance(&inst);
  EXPECT_NE(questRequest, nullptr);
  EXPECT_NE(dynamic_cast<KillWolvesQuest*>(questRequest->quest), nullptr);
  EXPECT_EQ(questRequest->status, Quest::Status::NotStarted);
}

TEST(GaiaTest, haveQuestRequestRetrievedByInProgressStatusMultiple) {
  Gaia gaia;
  QuestManager qm;
  PathosInstance inst;

  std::unique_ptr<QuestRequest> questRequest = gaia.retrieveQuestRequestWithInstance(&inst);
  EXPECT_NE(questRequest, nullptr);
  EXPECT_NE(dynamic_cast<KillWolvesQuest*>(questRequest->quest), nullptr);
  EXPECT_EQ(questRequest->status, Quest::Status::NotStarted);

  // Quest not complete, wolves < 20.
  Stats::instance()->setWolvesKilled(2);
  questRequest->quest->updateQuestStatus(&inst);

  questRequest = gaia.retrieveQuestRequestWithInstance(&inst);
  EXPECT_NE(questRequest, nullptr);
  EXPECT_NE(dynamic_cast<KillWolvesQuest*>(questRequest->quest), nullptr);
  EXPECT_EQ(questRequest->status, Quest::Status::InProgress);
}

TEST(GaiaTest, haveQuestRequestRetrievedByCompletedStatus) {
  Gaia gaia;
  QuestManager qm;
  PathosInstance inst;

  std::unique_ptr<QuestRequest> questRequest = gaia.retrieveQuestRequestWithInstance(&inst);
  EXPECT_NE(questRequest, nullptr);
  EXPECT_NE(dynamic_cast<KillWolvesQuest*>(questRequest->quest), nullptr);
  EXPECT_EQ(questRequest->status, Quest::Status::NotStarted);

  // Quest not complete, wolves < 20.
  Stats::instance()->setWolvesKilled(2);
  questRequest->quest->updateQuestStatus(&inst);

  questRequest = gaia.retrieveQuestRequestWithInstance(&inst);
  EXPECT_NE(questRequest, nullptr);
  EXPECT_NE(dynamic_cast<KillWolvesQuest*>(questRequest->quest), nullptr);
  EXPECT_EQ(questRequest->status, Quest::Status::InProgress);

  // >= 20 wolves killed.
  Stats::instance()->setWolvesKilled(23);
  questRequest->quest->updateQuestStatus(&inst);

  questRequest = gaia.retrieveQuestRequestWithInstance(&inst);
  EXPECT_NE(questRequest, nullptr);
  EXPECT_NE(dynamic_cast<KillWolvesQuest*>(questRequest->quest), nullptr);
  EXPECT_EQ(questRequest->status, Quest::Status::Completed);
}
