#ifndef PATHOS_ATHENA
#define PATHOS_ATHENA

#include "mob/friendly/romance/Romanceable.h"
#include "mob/friendly/quest/QuestGiver.h"

namespace Pathos {

class Athena : public Romanceable, public QuestGiver {
public:
  Athena() : Romanceable(), QuestGiver() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_ATHENA
