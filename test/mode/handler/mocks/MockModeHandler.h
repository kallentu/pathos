#ifndef PATHOS_MOCK_MODE_HANDLER
#define PATHOS_MOCK_MODE_HANDLER

#include "controller/Char.h"
#include "event/QuitEvent.h"
#include "mode/handler/ModeHandler.h"
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::ByMove;
using ::testing::Return;

namespace Pathos {

class MockModeHandler : public ModeHandler {
public:
  MockModeHandler() {
    // Returns QuitEvent to end test early
    // TODO: Perhaps change this to a mocked and more controlled event
    ON_CALL(*this, handle(_))
        .WillByDefault(Return(ByMove(std::make_unique<QuitEvent>())));
  }

  MOCK_METHOD1(handle, std::unique_ptr<Event>(const Char &));
};

} // namespace Pathos

#endif // PATHOS_MOCK_MODE_HANDLER
