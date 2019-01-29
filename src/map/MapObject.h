#ifndef PATHOS_MAP_OBJECT
#define PATHOS_MAP_OBJECT

#include "event/Event.h"
#include <memory>
#include <vector>

namespace Pathos {

class EventManager;

// A type of object that can be placed in a Map.
class MapObject {
public:
  // Used respectively to represent:
  // Player, Hostile, Friendly, Wall, Ground
  enum class Char { At, Lantern, Sterling, Bound, Empty };

  MapObject(Char c) : c{c} {}
  virtual ~MapObject() {}

  Char &getCharType() { return c; }

  virtual std::vector<std::unique_ptr<Event>>
  callEventManagerForEventList(EventManager *em) = 0;

private:
  // Object's symbol in the view.
  Char c;
};

} // namespace Pathos

#endif // PATHOS_MAP_OBJECT
