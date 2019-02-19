#ifndef PATHOS_ARTEMIS
#define PATHOS_ARTEMIS

#include "mob/friendly/romance/QuestGiverRomanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// Goddess of the hunt and chastity
class Artemis : public QuestGiverRomanceable {
public:
  Artemis() : QuestGiverRomanceable() {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_ARTEMIS
