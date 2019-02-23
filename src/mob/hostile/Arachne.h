#ifndef PATHOS_ARACHNE
#define PATHOS_ARACHNE

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Boss mob for level 51
class Arachne : public Hostile {
public:
  Arachne() : Hostile(7000000, 75000) {}

  void beAttackedBy(Player &p) override;
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_ARACHNE
