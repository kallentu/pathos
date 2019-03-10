#ifndef PATHOS_APOLLO
#define PATHOS_APOLLO

#include "mob/friendly/romance/QuestGiverRomanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// God of music, poetry, truth and prophecy
class Apollo : public QuestGiverRomanceable {
public:
  Apollo() : QuestGiverRomanceable("Apollo") {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_APOLLO
