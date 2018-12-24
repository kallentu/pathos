#ifndef PATHOS_PLAYER
#define PATHOS_PLAYER

#include "map/MapObject.h"
#include <cstddef>
#include <string>

namespace Pathos {

class Hostile;

class Player final : MapObject {
  std::string name;
  size_t health;
  size_t level;
  size_t experience;
  size_t damage;

public:
  Player() : MapObject(MapObject::Char::At) {}
  ~Player() {}

  size_t getHealth() const { return health; }
  void setHealth(size_t h) { health = h; }

  std::string getName() const { return name; }
  void setName(std::string n) { name = n; }

  size_t getLevel() const { return level; }
  void setLevel(size_t l) { level = l; }

  size_t getExperience() const { return experience; }
  void setExperience(size_t ex) { experience = ex; }

  size_t getDamage() const { return damage; }
  void setDamage(size_t d) { damage = d; }

  void attack(Hostile *h) { h->beAttackedBy(*this); }
};

} // namespace Pathos

#endif // PATHOS_PLAYER
