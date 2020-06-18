#ifndef PATHOS_CERBERUS
#define PATHOS_CERBERUS

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Boss mob for level 35
class Cerberus : public Hostile {
public:
  Cerberus() : Hostile("Cerberus", 250000, 1250, 250) {}

private:
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_CERBERUS
