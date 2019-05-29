#ifndef PATHOS_CHECK_VICINITY_EVENT
#define PATHOS_CHECK_VICINITY_EVENT

#include "event/Event.h"

namespace Pathos {

class PathosInstance;

/** Checks the four places around the player for NPC, hostiles. */
class CheckVicinityEvent : public Event {
public:
  CheckVicinityEvent();
  void begin(PathosInstance *inst) override;
};

} // namespace Pathos

#endif
