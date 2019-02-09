#ifndef PATHOS_HEPHAESTUS
#define PATHOS_HEPHAESTUS

#include "mob/friendly/romance/Romanceable.h"
#include "mob/friendly/quest/QuestGiver.h"

namespace Pathos {

class Hephaestus : public Romanceable, public QuestGiver {
public:
  Hephaestus() : Romanceable(), QuestGiver() {}

  // TODO: Override when view is ready.
  void talkedToBy(Player &p) {}
};

} // namespace Pathos

#endif // PATHOS_HEPHAESTUS
