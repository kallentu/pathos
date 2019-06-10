#ifndef PATHOS_LEAVE_MODE_EVENT
#define PATHOS_LEAVE_MODE_EVENT

#include <memory>

#include "core/PathosInstance.h"
#include "event/Event.h"
#include "request/ClearQuickStatusRequest.h"

namespace Pathos {

class LeaveModeEvent : public Event {
public:
  void begin(PathosInstance *inst) {
    // Clear the line for future usage or just makes sense
    // when player walks away.
    std::unique_ptr<ClearQuickStatusRequest> req =
        std::make_unique<ClearQuickStatusRequest>();
    inst->notify(req.get());

    // Quit the current, active mode and continue on the previous
    inst->leaveMode();
  }
};

} // namespace Pathos

#endif
