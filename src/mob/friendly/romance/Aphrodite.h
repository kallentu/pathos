#ifndef PATHOS_APHRODITE
#define PATHOS_APHRODITE

#include "mob/friendly/quest/QuestGiver.h"
#include "mob/friendly/romance/Romanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

class Aphrodite : public Romanceable, public QuestGiver {
public:
  Aphrodite() : Romanceable(), QuestGiver() {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_APHRODITE
