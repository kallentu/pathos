#ifndef PATHOS_QUEST_MANAGER
#define PATHOS_QUEST_MANAGER

#include "quest/Quest.h"
#include <map>
#include <memory>
#include <string>

namespace Pathos {

  class Gaia;

  class Ariadne;

  class QuestRequest;

  class PathosInstance;

  class QuestManager final {
    // Store quest name and quest object
    std::map<std::string, std::unique_ptr<Quest>> quests;

  public:
    std::unique_ptr<QuestRequest> getQuestRequest(Gaia &gaia,
                                                  PathosInstance *inst);

    std::unique_ptr<QuestRequest> getQuestRequest(Ariadne &ariadne,
                                                  PathosInstance *inst);

  private:
    std::unique_ptr<QuestRequest> getRequestFromStatus(Quest::Status status,
                                                       Quest *quest,
                                                       PathosInstance *inst);
  };

} // namespace Pathos

#endif
