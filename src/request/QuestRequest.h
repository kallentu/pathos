#ifndef PATHOS_QUEST_REQUEST
#define PATHOS_QUEST_REQUEST

#include "quest/Quest.h"
#include "request/ViewRequest.h"

namespace Pathos {

class View;

// A request for abstract quests.
struct QuestRequest : public ViewRequest {
  Quest::Status status;
  Quest *quest;

public:
  QuestRequest(Quest::Status &status, Quest *quest)
      : status{status}, quest{quest} {}
  void beDrawnBy(View &view) const override;
};

} // namespace Pathos

#endif // PATHOS_QUEST_REQUEST
