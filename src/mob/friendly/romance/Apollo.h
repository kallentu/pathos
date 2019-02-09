#ifndef PATHOS_APOLLO
#define PATHOS_APOLLO

#include "mob/friendly/romance/Romanceable.h"
#include "mob/friendly/quest/QuestGiver.h"

namespace Pathos {

class Apollo : public Romanceable. public QuestGiver {
public:
  Apollo() : Romanceable(), QuestGiver() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_APOLLO
