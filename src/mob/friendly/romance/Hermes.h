#ifndef PATHOS_HERMES
#define PATHOS_HERMES

#include "mob/friendly/romance/Romanceable.h"
#include "mob/friendly/quest/QuestGiver.h"

namespace Pathos {

class Hermes : public Romanceable, public QuestGiver {
public:
  Hermes() : Romanceable(), QuestGiver() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_HERMES
