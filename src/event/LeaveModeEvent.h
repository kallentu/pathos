#ifndef PATHOS_LEAVE_MODE_EVENT
#define PATHOS_LEAVE_MODE_EVENT

#include <memory>

#include "core/PathosInstance.h"
#include "event/Event.h"
#include "request/ClearEntireStatus.h"

namespace Pathos {

class LeaveModeEvent : public Event {
public:
  void begin(PathosInstance *inst) override {
    // Clear prior main and quick status since we moved.
    std::unique_ptr<ClearEntireStatus> clearReq =
        std::make_unique<ClearEntireStatus>();
    inst->notify(clearReq.get());

    // Quit the current, active mode and continue on the previous
    inst->leaveMode();
  }
};

} // namespace Pathos

#endif
