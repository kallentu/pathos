#ifndef PATHOS_GAIA
#define PATHOS_GAIA

#include "mob/friendly/quest/QuestGiver.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

class Gaia : public QuestGiver {
public:
  Gaia() : QuestGiver() {}

  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_GAIA
