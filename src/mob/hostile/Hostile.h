#ifndef PATHOS_HOSTILE
#define PATHOS_HOSTILE

#include "map/MapObject.h"
#include <cstddef>

namespace Pathos {

class Player;

// Hostile mobs will attack the Player and other Friendly NPCs.
// Will attack them within range of 1 square.
class Hostile : MapObject {
  size_t health;
  size_t damage;
  bool deceased;

public:
  Hostile(size_t health, size_t damage)
      : MapObject(MapObject::Char::Lantern), health{health}, damage{damage},
        deceased{false} {}
  virtual ~Hostile() {}

  size_t getHealth() const { return health; }
  void setHealth(size_t h) { health = h; }

  size_t getDamage() const { return damage; }
  void setDamage(size_t d) { damage = d; }

  bool isDeceased() const { return deceased; }
  void setDeceased(bool d) { deceased = d; }

  virtual void beAttackedBy(Player &p) = 0;
};

} // namespace Pathos

#endif // PATHOS_HOSTILE
