#ifndef PATHOS_MOB
#define PATHOS_MOB

namespace Pathos {

class Chicken;
class SmallPotion;
class Bow;
class Greatsword;
class Staff;

class Mob {
public:
  virtual ~Mob() {}

  // Consumable items
  virtual void consume(Chicken &c) = 0;
  virtual void consume(SmallPotion &sp) = 0;

  // Interactable items
  virtual void equip(Bow &b) = 0;
  virtual void equip(Greatsword &gs) = 0;
  virtual void equip(Staff &s) = 0;
};

} // namespace Pathos

#endif // PATHOS_MOB
