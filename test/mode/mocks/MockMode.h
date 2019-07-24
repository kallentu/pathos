#ifndef PATHOS_MOCK_MODE
#define PATHOS_MOCK_MODE

#include "mode/Mode.h"
#include "mode/handler/mocks/MockModeHandler.h"
#include <gmock/gmock.h>

using ::testing::Return;

namespace Pathos {

class MockMode : public Mode {
  std::unique_ptr<MockModeHandler> handler;

public:
  MockMode(PathosInstance *inst)
      : Mode(inst), handler{std::make_unique<MockModeHandler>()} {
    ON_CALL(*this, getHandler()).WillByDefault(Return(handler.get()));
  }

  MOCK_CONST_METHOD0(getHandler, ModeHandler *());
};

} // namespace Pathos

#endif // PATHOS_MOCK_MODE
