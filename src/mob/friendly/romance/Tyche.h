#ifndef PATHOS_TYCHE
#define PATHOS_TYCHE

#include "mob/friendly/romance/QuestGiverRomanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// Goddess of luck and fortune
class Tyche : public QuestGiverRomanceable {
public:
  Tyche() : QuestGiverRomanceable() {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_TYCHE
