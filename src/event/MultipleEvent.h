#ifndef PATHOS_MULTIPLE_EVENT
#define PATHOS_MULTIPLE_EVENT

#include "event/Event.h"
#include <memory>
#include <vector>

namespace Pathos {

class PathosInstance;

class MultipleEvent : public Event {
  std::vector<std::unique_ptr<Event>> events;

public:
  MultipleEvent();
  void begin(PathosInstance *inst) override;

  void addEvent(std::unique_ptr<Event> event);
};

} // namespace Pathos

#endif
