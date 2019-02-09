#ifndef PATHOS_DIONYSUS
#define PATHOS_DIONYSUS

#include "mob/friendly/romance/Romanceable.h"
#include "mob/friendly/quest/QuestGiver.h"

namespace Pathos {

class Dionysus : public Romanceable, public QuestGiver {
public:
  Dionysus() : Romanceable(), QuestGiver() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_DIONYSUS
