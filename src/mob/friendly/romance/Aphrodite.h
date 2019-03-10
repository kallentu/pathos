#ifndef PATHOS_APHRODITE
#define PATHOS_APHRODITE

#include "mob/friendly/romance/QuestGiverRomanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// Goddess of love, beauty and passion
class Aphrodite : public QuestGiverRomanceable {
public:
  Aphrodite() : QuestGiverRomanceable("Aphrodite") {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_APHRODITE
