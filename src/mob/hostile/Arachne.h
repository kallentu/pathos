#ifndef PATHOS_ARACHNE
#define PATHOS_ARACHNE

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Boss mob for level 51
class Arachne : public Hostile {
public:
  Arachne() : Hostile("Arachne", 7000000, 70000, 5000) {}

private:
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_ARACHNE
