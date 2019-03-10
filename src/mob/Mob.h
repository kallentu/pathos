#ifndef PATHOS_MOB
#define PATHOS_MOB

#include <string>

namespace Pathos {

class Chicken;
class SmallPotion;
class Bow;
class Greatsword;
class Staff;

class Mob {
protected:
  std::string name;
  size_t health;
  size_t magicDamage;
  size_t physicalDamage;
  bool deceased;

public:
  Mob(std::string name, size_t health, size_t magicDamage,
      size_t physicalDamage)
      : name{name}, health{health}, magicDamage{magicDamage},
        physicalDamage{physicalDamage}, deceased{false} {}
  virtual ~Mob() {}

  std::string getName() const { return name; }
  void setName(std::string n) { name = n; }

  size_t getHealth() const { return health; }
  void setHealth(size_t h) { health = h; }

  size_t getMagicDamage() const { return magicDamage; }
  void setMagicDamage(size_t md) { magicDamage = md; }

  size_t getPhysicalDamage() const { return physicalDamage; }
  void setPhysicalDamage(size_t pd) { physicalDamage = pd; }

  bool isDeceased() const { return deceased; }
  void setDeceased(bool d) { deceased = d; }

  // Consumable items
  virtual void consume(Chicken &c) = 0;
  virtual void consume(SmallPotion &sp) = 0;

  // Interactable items
  // Bows has 9/10 physical + 1/10 magic damage.
  virtual void equip(Bow &b) = 0;

  // GS are all physical damage.
  virtual void equip(Greatsword &gs) = 0;

  // Staffs are all magical damage.
  virtual void equip(Staff &s) = 0;
};

} // namespace Pathos

#endif // PATHOS_MOB
