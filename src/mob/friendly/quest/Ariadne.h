#ifndef PATHOS_ARIADNE
#define PATHOS_ARIADNE

#include "mob/friendly/Friendly.h"
#include "mob/friendly/quest/QuestGiver.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// Cretian princess, known for her involvement with the Labyrinth
class Ariadne : public QuestGiver, public Friendly {
public:
  Ariadne() : QuestGiver(), Friendly("Ariadne") {}

  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_ARIADNE
