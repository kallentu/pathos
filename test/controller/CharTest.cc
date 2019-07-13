#include "controller/Char.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(CharTest, ReturnNumberValue) {
  Char c(38);
  ASSERT_EQ(38, c.numValue());
}

TEST(CharTest, ReturnCharValue) {
  Char c(38);
  ASSERT_EQ('&', c.charValue());
}
