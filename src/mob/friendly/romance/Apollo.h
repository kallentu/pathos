#ifndef PATHOS_APOLLO
#define PATHOS_APOLLO

#include "mob/friendly/quest/QuestGiver.h"
#include "mob/friendly/romance/Romanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

class Apollo : public Romanceable, public QuestGiver {
public:
  Apollo() : Romanceable(), QuestGiver() {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_APOLLO
