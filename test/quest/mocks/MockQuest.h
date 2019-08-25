#ifndef PATHOS_MOCK_QUEST
#define PATHOS_MOCK_QUEST

#include "quest/Quest.h"
#include <gmock/gmock.h>

namespace Pathos {

class MockQuest : public Quest {
public:
  MockQuest(QuestGiver *questGiver) : Quest(questGiver) {}

  Status checkConditions(PathosInstance *inst) override {
    (void)inst; // Mock, not necessary to use inst
    return Quest::Status::Completed;
  }
};

} // namespace Pathos

#endif // PATHOS_MOCK_QUEST
