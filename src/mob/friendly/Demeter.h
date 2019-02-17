#ifndef PATHOS_DEMETER
#define PATHOS_DEMETER

#include "mob/friendly/Friendly.h"

namespace Pathos {

class Player;
class TalkRequest;

class Demeter : public Friendly {
public:
  Demeter() : Friendly() {}
  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_DEMETER
