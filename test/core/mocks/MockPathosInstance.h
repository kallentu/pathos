#ifndef PATHOS_MOCK_PATHOS_INSTANCE
#define PATHOS_MOCK_PATHOS_INSTANCE

#include "core/PathosInstance.h"
#include "view/curses/NcursesView.h"
#include <gmock/gmock.h>

using ::testing::Return;

namespace Pathos {

class MockPathosInstance : public PathosInstance {
public:
  MockPathosInstance() : PathosInstance() {
    // Don't want to use any views while testing
    clearObservers();

    // Also, don't want to actually run the game with a mock
    ON_CALL(*this, run()).WillByDefault(Return());
  }

  MOCK_METHOD0(run, void());
};

} // namespace Pathos

#endif // PATHOS_MOCK_PATHOS_INSTANCE
