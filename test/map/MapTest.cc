#include "map/Map.h"
#include "controller/Char.h"
#include "map/Wall.h"
#include "map/mocks/MockMapObject.h"
#include <gtest/gtest.h>

using namespace Pathos;

const size_t kHeight = 5;
const size_t kWidth = 5;

TEST(MapTest, ConstructorGetHeight) {
  Map map{kHeight, kWidth};

  // Height is inside the walls
  // The height we get is the outter wall, same with 0
  EXPECT_EQ(map.getHeight(), kHeight + 1);
}

TEST(MapTest, ConstructorGetWidth) {
  Map map{kHeight, kWidth};

  // Width is inside the walls
  // The width we get is the outter wall, same with 0
  EXPECT_EQ(map.getWidth(), kWidth + 1);
}

TEST(MapTest, GetObjectWall) {
  Map map{kHeight, kWidth};

  // Found Wall object
  EXPECT_NE(dynamic_cast<Wall *>(map.get(0, 0)), nullptr);
}

TEST(MapTest, AddObjectToPositionReturnSameObject) {
  Map map{kHeight, kWidth};
  std::unique_ptr<MockMapObject> mockMapObject =
      std::make_unique<MockMapObject>(MapObject::Char::Lantern);
  MockMapObject *mockMapObjectPtr = mockMapObject.get();

  map.addObjectToPosition(std::move(mockMapObject), 2, 2);

  EXPECT_EQ(dynamic_cast<MockMapObject *>(map.get(2, 2)), mockMapObjectPtr);
}

TEST(MapTest, AddObjectToPositionRemoveFromPositionSameObject) {
  Map map{kHeight, kWidth};

  map.addObjectToPosition(
      std::make_unique<MockMapObject>(MapObject::Char::Lantern), 2, 2);
  map.removeObjectFromPosition(2, 2);

  EXPECT_EQ(dynamic_cast<MockMapObject *>(map.get(2, 2)), nullptr);
}
