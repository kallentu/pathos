#ifndef PATHOS_MOCK_QUEST_GIVER
#define PATHOS_MOCK_QUEST_GIVER

#include "core/PathosInstance.h"
#include "mob/friendly/quest/QuestGiver.h"
#include "request/QuestRequest.h"
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::Return;

namespace Pathos {

class MockQuestGiver : public QuestGiver {
public:
  MockQuestGiver() : QuestGiver() {}

  std::unique_ptr<QuestRequest>
  haveQuestRequestRetrievedBy(QuestManager *qm, PathosInstance *inst) override {
    (void)qm;
    (void)inst;
    return nullptr; // TODO: Perhaps a mock quest request if needed
  }
};

} // namespace Pathos

#endif // PATHOS_MOCK_QUEST_GIVER
