#ifndef PATHOS_HADES
#define PATHOS_HADES

#include "mob/friendly/Friendly.h"

namespace Pathos {

class Player;
class TalkRequest;

// God of the underworld and the undead.
class Hades : public Friendly {
public:
  Hades() : Friendly() {}
  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_HADES
