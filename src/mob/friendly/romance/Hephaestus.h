#ifndef PATHOS_HEPHAESTUS
#define PATHOS_HEPHAESTUS

#include "mob/friendly/quest/QuestGiver.h"
#include "mob/friendly/romance/Romanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

class Hephaestus : public Romanceable, public QuestGiver {
public:
  Hephaestus() : Romanceable(), QuestGiver() {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_HEPHAESTUS
