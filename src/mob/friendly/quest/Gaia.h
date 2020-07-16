#ifndef PATHOS_GAIA
#define PATHOS_GAIA

#include "mob/friendly/Friendly.h"
#include "mob/friendly/quest/QuestGiver.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;
class QuestManager;
class QuestRequest;
class PathosInstance;

// Mother of all life and Earth itself
class Gaia : public QuestGiver, public Friendly {
public:
  Gaia() : QuestGiver(), Friendly("Gaia") {}

  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
  std::unique_ptr<QuestRequest>
  retrieveQuestRequestWithInstance(PathosInstance *inst) override;
};

} // namespace Pathos

#endif // PATHOS_GAIA
