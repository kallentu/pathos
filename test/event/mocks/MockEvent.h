#ifndef PATHOS_MOCK_EVENT
#define PATHOS_MOCK_EVENT

#include "event/Event.h"
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::Return;

namespace Pathos {

class MockEvent : public Event {
public:
  MockEvent() : Event() { ON_CALL(*this, begin(_)).WillByDefault(Return()); }

  MOCK_METHOD1(begin, void(PathosInstance *));
};

} // namespace Pathos

#endif // PATHOS_MOCK_EVENT
