#ifndef PATHOS_ARES
#define PATHOS_ARES

#include "mob/friendly/romance/QuestGiverRomanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// God of war
class Ares : public QuestGiverRomanceable {
public:
  Ares() : QuestGiverRomanceable("Ares") {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_ARES
