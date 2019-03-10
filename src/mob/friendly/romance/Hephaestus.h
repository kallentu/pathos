#ifndef PATHOS_HEPHAESTUS
#define PATHOS_HEPHAESTUS

#include "mob/friendly/romance/QuestGiverRomanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// God of the forge, blacksmiths
class Hephaestus : public QuestGiverRomanceable {
public:
  Hephaestus() : QuestGiverRomanceable("Hephaestus") {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_HEPHAESTUS
