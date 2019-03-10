#ifndef PATHOS_ENRAGED_BULL
#define PATHOS_ENRAGED_BULL

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Mob for level 35-40 area
class EnragedBull : public Hostile {
public:
  EnragedBull() : Hostile("Enraged Bull", 30000, 0, 2000) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_ENRAGED_BULL
