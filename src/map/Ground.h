#ifndef PATHOS_GROUND
#define PATHOS_GROUND

#include "event/Event.h"
#include "event/EventManager.h"
#include "map/MapObject.h"
#include <memory>
#include <vector>

namespace Pathos {

class Ground : public MapObject {
public:
  Ground() : MapObject(MapObject::Char::Empty) {}
  ~Ground() {}

  std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) override {
    return em->getEventList(*this);
  }
};

} // namespace Pathos

#endif // PATHOS_GROUND
