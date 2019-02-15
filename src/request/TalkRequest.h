#ifndef PATHOS_TALK_REQUEST
#define PATHOS_TALK_REQUEST

#include "request/ViewRequest.h"
#include <string>

namespace Pathos {

// A request to show NPC dialogue, one line at a time.
struct TalkRequest : public ViewRequest {
  std::string npcDialogue;

  TalkRequest(std::string dialogue);
  void beDrawnBy(View &view) const override;
};

} // namespace Pathos

#endif // PATHOS_TALK_REQUEST
