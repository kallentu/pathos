#ifndef PATHOS_DEMETER
#define PATHOS_DEMETER

#include "mob/friendly/Friendly.h"

namespace Pathos {

class Player;
class TalkRequest;

// Goddess of agriculture and harvest
class Demeter : public Friendly {
public:
  Demeter() : Friendly("Demeter") {}
  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_DEMETER
