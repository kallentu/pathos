#include "map/mocks/MockMapObject.h"
#include <gtest/gtest.h>

using namespace Pathos;

TEST(MapObjectTest, GetCharTypeReturnsSameChar) {
  MockMapObject mockMapObject = MockMapObject(MapObject::Char::Lantern);

  EXPECT_EQ(mockMapObject.getCharType(), MapObject::Char::Lantern);
}
