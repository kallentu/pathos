#ifndef PATHOS_HOSTILE
#define PATHOS_HOSTILE

#include <cstddef>
#include "map/MapObject.h"

namespace Pathos {

class Player;

class Hostile : MapObject {
  size_t health;
  bool deceased;

public:
  Hostile(size_t health)
      : MapObject(MapObject::Char::Lantern), health{health}, deceased{false} {}
  virtual ~Hostile() {}

  size_t getHealth() const { return health; }
  void setHealth(size_t h) { health = h; }

  bool isDeceased() const { return deceased; }
  void setDeceased(bool d) { deceased = d; }

  virtual void beAttackedBy(Player &p) = 0;
};

} // namespace Pathos

#endif // PATHOS_HOSTILE
