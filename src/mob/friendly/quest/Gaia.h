#ifndef PATHOS_GAIA
#define PATHOS_GAIA

#include "mob/friendly/Friendly.h"
#include "mob/friendly/quest/QuestGiver.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;
class Quest;

// Mother of all life and Earth itself
class Gaia : public QuestGiver, public Friendly {
public:
  Gaia(Quest *quest) : QuestGiver(quest), Friendly("Gaia") {}

  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_GAIA
