#ifndef PATHOS_ARIADNE
#define PATHOS_ARIADNE

#include "mob/friendly/quest/QuestGiver.h"

namespace Pathos {

class Ariadne : public QuestGiver {
public:
  Ariadne() : QuestGiver() {}

  // TODO: override
  void beTalkedToBy(Player &p) override {}
};

} // namespace Pathos

#endif // PATHOS_ARIADNE
