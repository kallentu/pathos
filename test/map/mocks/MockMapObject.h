#ifndef PATHOS_MOCK_MAP_OBJECT
#define PATHOS_MOCK_MAP_OBJECT

#include "map/MapObject.h"
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::Return;

namespace Pathos {

class MockMapObject : public MapObject {
public:
  MockMapObject(MapObject::Char c) : MapObject(c) {}
};

} // namespace Pathos

#endif // PATHOS_MOCK_MAP_OBJECT
