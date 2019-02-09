#ifndef PATHOS_APHRODITE
#define PATHOS_APHRODITE

#include "mob/friendly/romance/Romanceable.h"
#include "mob/friendly/quest/QuestGiver.h"

namespace Pathos {

class Aphrodite : public Romanceable, public QuestGiver {
public:
  Aphrodite() : Romanceable(), QuestGiver() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_APHRODITE
