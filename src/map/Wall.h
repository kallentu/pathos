#ifndef PATHOS_WALL
#define PATHOS_WALL

#include "event/Event.h"
#include "event/EventManager.h"
#include "map/MapObject.h"
#include <memory>
#include <vector>

namespace Pathos {

class Wall : public MapObject {
public:
  Wall() : MapObject(MapObject::Char::Bound) {}
  ~Wall() {}

  std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) override {
    return em->getEventList(*this);
  }
};

} // namespace Pathos

#endif // PATHOS_WALL
