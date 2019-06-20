#ifndef PATHOS_CLEAR_TALK_REQUEST
#define PATHOS_CLEAR_TALK_REQUEST

#include "request/ViewRequest.h"

namespace Pathos {

class View;

// A request for clearing the NPC dialogue on the StatusView.
struct ClearTalkRequest : public ViewRequest {
public:
  void beDrawnBy(View &view) const override;
};

} // namespace Pathos

#endif // PATHOS_CLEAR_TALK_REQUEST
