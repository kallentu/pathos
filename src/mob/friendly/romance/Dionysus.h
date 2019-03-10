#ifndef PATHOS_DIONYSUS
#define PATHOS_DIONYSUS

#include "mob/friendly/romance/QuestGiverRomanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// God of wine and theatre
class Dionysus : public QuestGiverRomanceable {
public:
  Dionysus() : QuestGiverRomanceable("Dionysus") {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_DIONYSUS
