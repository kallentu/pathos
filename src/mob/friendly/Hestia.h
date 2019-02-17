#ifndef PATHOS_HESTA
#define PATHOS_HESTA

#include "mob/friendly/Friendly.h"

namespace Pathos {

class Player;
class TalkRequest;

class Hestia : public Friendly {
public:
  Hestia() : Friendly() {}
  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_HESTA
