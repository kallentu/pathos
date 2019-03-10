#ifndef PATHOS_POSEIDON
#define PATHOS_POSEIDON

#include "mob/friendly/Friendly.h"

namespace Pathos {

class Player;
class TalkRequest;

// God of the sea, earthquakes and horses
class Poseidon : public Friendly {
public:
  Poseidon() : Friendly("Poseidon") {}
  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_POSEIDON
