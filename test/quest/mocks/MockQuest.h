#ifndef PATHOS_MOCK_QUEST
#define PATHOS_MOCK_QUEST

#include "quest/Quest.h"
#include <gmock/gmock.h>

namespace Pathos {

class MockQuest : public Quest {
  Quest::Status condition = NotStarted;
public:
  MockQuest(QuestGiver *questGiver) : Quest(questGiver) {}

  // To bypass that we can't set status ourselves, but we would still like to for testing purposes.
  void setCondition(Status status) {
    condition = status;
  }

  Status checkConditions(PathosInstance *inst) override {
    (void)inst; // Mock, not necessary to use inst
    return condition;
  }
};

} // namespace Pathos

#endif // PATHOS_MOCK_QUEST
