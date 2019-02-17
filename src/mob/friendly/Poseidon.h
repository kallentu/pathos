#ifndef PATHOS_POSEIDON
#define PATHOS_POSEIDON

#include "mob/friendly/Friendly.h"

namespace Pathos {

class Player;
class TalkRequest;

class Poseidon : public Friendly {
public:
  Poseidon() : Friendly() {}
  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_POSEIDON
