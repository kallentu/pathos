#ifndef PATHOS_MINOTAUR
#define PATHOS_MINOTAUR

#include "mob/hostile/Hostile.h"

namespace Pathos {

class Player;

// Boss mob for level 40
class Minotaur : public Hostile {
public:
  Minotaur() : Hostile("Minotaur", 100000, 0, 5000) {}

private:
  void beKilledBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_MINOTAUR
