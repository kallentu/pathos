#ifndef PATHOS_ARIADNE
#define PATHOS_ARIADNE

#include "mob/friendly/Friendly.h"
#include "mob/friendly/quest/QuestGiver.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;
class QuestManager;
class QuestRequest;
class PathosInstance;

// Cretian princess, known for her involvement with the Labyrinth
class Ariadne : public QuestGiver, public Friendly {
public:
  Ariadne() : QuestGiver(), Friendly("Ariadne") {}

  std::unique_ptr<TalkRequest> beTalkedToBy(Player &p) override;
  std::unique_ptr<QuestRequest>
  haveQuestRequestRetrievedBy(QuestManager *qm, PathosInstance *inst) override;
};

} // namespace Pathos

#endif // PATHOS_ARIADNE
