#ifndef PATHOS_MOCK_PATHOS_INSTANCE
#define PATHOS_MOCK_PATHOS_INSTANCE

#include "core/PathosInstance.h"
#include "view/curses/NcursesView.h"
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::Return;

namespace Pathos {

class MockPathosInstance : public PathosInstance {
public:
  MockPathosInstance() : PathosInstance() {
    ON_CALL(*this, addObserver(_)).WillByDefault(Return());
  }

  // Make sure we don't add anything to notify
  MOCK_METHOD1(addObserver, void(NcursesView *));
};

} // namespace Pathos

#endif // PATHOS_MOCK_MODE_HANDLER
