#ifndef PATHOS_MOB_KILLED_EVENT
#define PATHOS_MOB_KILLED_EVENT

#include "event/Event.h"

namespace Pathos {

  class PathosInstance;

  class MobKilledEvent : public Event {
  public:
    MobKilledEvent() : Event() {}

    void begin(PathosInstance *inst) override;
  };

} // namespace Pathos

#endif // PATHOS_MOB_KILLED_EVENT
