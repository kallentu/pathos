#ifndef PATHOS_QUIT_EVENT
#define PATHOS_QUIT_EVENT

#include "event/Event.h"

namespace Pathos {

class PathosInstance;

class QuitEvent : public Event {
public:
  QuitEvent() : Event() {}

  void begin(PathosInstance *inst) override;
};

} // namespace Pathos

#endif // PATHOS_QUIT_EVENT
