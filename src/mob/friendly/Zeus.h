#ifndef PATHOS_ZEUS
#define PATHOS_ZEUS

#include "mob/friendly/Friendly.h"

namespace Pathos {

class Player;
class TalkRequest;

// King of Gods, god of the sky
class Zeus : public Friendly {
public:
  Zeus() : Friendly() {}
  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_ZEUS
