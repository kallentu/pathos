#ifndef PATHOS_TYCHE
#define PATHOS_TYCHE

#include "mob/friendly/romance/Romanceable.h"
#include "mob/friendly/quest/QuestGiver.h"

namespace Pathos {

class Tyche : public Romanceable, public QuestGiver {
public:
  Tyche() : Romanceable(), QuestGiver() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_TYCHE
