#ifndef PATHOS_ARTEMIS
#define PATHOS_ARTEMIS

#include "mob/friendly/romance/Romanceable.h"
#include "mob/friendly/quest/QuestGiver.h"

namespace Pathos {

class Artemis : public Romanceable, public QuestGiver {
public:
  Artemis() : Romanceable(), QuestGiver() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_ARTEMIS
