#ifndef PATHOS_ARES
#define PATHOS_ARES

#include "mob/friendly/romance/Romanceable.h"
#include "mob/friendly/quest/QuestGiver.h"

namespace Pathos {

class Ares : public Romanceable, public QuestGiver {
public:
  Ares() : Romanceable(), QuestGiver() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_ARES
