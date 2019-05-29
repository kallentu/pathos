#include "event/MultipleEvent.h"
#include "core/PathosInstance.h"
#include "event/Event.h"
#include <memory>
#include <vector>

using namespace Pathos;

MultipleEvent::MultipleEvent() : Event() {}

void MultipleEvent::begin(PathosInstance *inst) {
  for (auto &event : events) {
    event->begin(inst);
  }
}

void MultipleEvent::addEvent(std::unique_ptr<Event> event) {
  events.push_back(std::move(event));
}
