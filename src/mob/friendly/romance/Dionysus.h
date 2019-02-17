#ifndef PATHOS_DIONYSUS
#define PATHOS_DIONYSUS

#include "mob/friendly/quest/QuestGiver.h"
#include "mob/friendly/romance/Romanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

class Dionysus : public Romanceable, public QuestGiver {
public:
  Dionysus() : Romanceable(), QuestGiver() {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_DIONYSUS
