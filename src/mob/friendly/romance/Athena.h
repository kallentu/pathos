#ifndef PATHOS_ATHENA
#define PATHOS_ATHENA

#include "mob/friendly/romance/QuestGiverRomanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// Goddess of intelligence and handicraft
class Athena : public QuestGiverRomanceable {
public:
  Athena() : QuestGiverRomanceable("Athena") {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_ATHENA
