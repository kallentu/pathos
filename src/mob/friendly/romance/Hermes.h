#ifndef PATHOS_HERMES
#define PATHOS_HERMES

#include "mob/friendly/quest/QuestGiver.h"
#include "mob/friendly/romance/Romanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

class Hermes : public Romanceable, public QuestGiver {
public:
  Hermes() : Romanceable(), QuestGiver() {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_HERMES
