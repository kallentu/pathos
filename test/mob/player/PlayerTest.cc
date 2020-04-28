#include <gtest/gtest.h>
#include <mob/player/Player.h>

using namespace Pathos;

// TODO (kallentu): Tests for attacking, consuming, equipping, and event list.

TEST(PlayerTest, Initialization) {
  Player player;

  EXPECT_EQ(player.getName(), "Periphas");
  EXPECT_EQ(player.getDrachma(), 500);
  EXPECT_EQ(player.getLevel(), 0);
  EXPECT_EQ(player.getExperience(), 0);
  EXPECT_EQ(player.getMagicDamage(), 5);
  EXPECT_EQ(player.getPhysicalDamage(), 5);
  EXPECT_EQ(player.getHealth(), 100);
}

TEST(PlayerTest, SetLevel) {
  Player player;

  player.setLevel(10);
  EXPECT_EQ(player.getLevel(), 10);
}

TEST(PlayerTest, SetAddExperience) {
  Player player;

  player.setExperience(10);
  EXPECT_EQ(player.getExperience(), 10);

  player.addExperience(2);
  EXPECT_EQ(player.getExperience(), 12);
}

TEST(PlayerTest, SetExperience) {
  Player player;

  player.setExperience(10);
  EXPECT_EQ(player.getExperience(), 10);
}
