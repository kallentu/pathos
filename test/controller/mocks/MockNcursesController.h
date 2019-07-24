#ifndef PATHOS_MOCK_NCURSES_CONTROLLER
#define PATHOS_MOCK_NCURSES_CONTROLLER

#include "controller/NcursesController.h"
#include <gmock/gmock.h>

using ::testing::ByMove;
using ::testing::Return;

namespace Pathos {

class MockNcursesController : public NcursesController {
public:
  MockNcursesController() : NcursesController(nullptr) {
    // Returns character A
    ON_CALL(*this, getInput())
        .WillByDefault(Return(ByMove(std::make_unique<Char>(65))));
  }

  MOCK_METHOD0(getInput, std::unique_ptr<Input>());
};

} // namespace Pathos

#endif // PATHOS_MOCK_NCURSES_CONTROLLER
