#ifndef PATHOS_LEAVE_MODE_EVENT
#define PATHOS_LEAVE_MODE_EVENT

#include <memory>

#include "core/PathosInstance.h"
#include "event/Event.h"
#include "request/ClearQuickStatusRequest.h"
#include "request/ClearTalkRequest.h"

namespace Pathos {

class LeaveModeEvent : public Event {
public:
  void begin(PathosInstance *inst) {
    // Clear prior NPC dialogue since we moved.
    std::unique_ptr<ClearTalkRequest> clearTalkReq =
        std::make_unique<ClearTalkRequest>();
    inst->notify(clearTalkReq.get());

    // Clear the line for future usage or just makes sense
    // when player walks away.
    std::unique_ptr<ClearQuickStatusRequest> clearStatusReq =
        std::make_unique<ClearQuickStatusRequest>();
    inst->notify(clearStatusReq.get());

    // Quit the current, active mode and continue on the previous
    inst->leaveMode();
  }
};

} // namespace Pathos

#endif
