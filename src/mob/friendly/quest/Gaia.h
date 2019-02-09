#ifndef PATHOS_GAIA
#define PATHOS_GAIA

#include "mob/friendly/quest/QuestGiver.h"

namespace Pathos {

class Gaia : public QuestGiver {
public:
  Gaia() : QuestGiver() {}

  // TODO: override
  void beTalkedToBy(Player &p) override {}
};

} // namespace Pathos

#endif // PATHOS_GAIA
