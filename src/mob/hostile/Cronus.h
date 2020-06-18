#ifndef PATHOS_CRONUS
#define PATHOS_CRONUS

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Boss mob for level 50
class Cronus : public Hostile {
public:
  Cronus() : Hostile("Cronus", 5000000, 20000, 30000) {}

private:
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_CRONUS
