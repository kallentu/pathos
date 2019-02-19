#ifndef PATHOS_HERA
#define PATHOS_HERA

#include "mob/friendly/Friendly.h"

namespace Pathos {

class Player;
class TalkRequest;

// Queen of Gods, goddess of marriage and birth
class Hera : public Friendly {
public:
  Hera() : Friendly() {}
  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_HERA
