#ifndef PATHOS_HERMES
#define PATHOS_HERMES

#include "mob/friendly/romance/QuestGiverRomanceable.h"
#include <memory>

namespace Pathos {

class Player;
class TalkRequest;

// Messenger of the gods, trickster
class Hermes : public QuestGiverRomanceable {
public:
  Hermes() : QuestGiverRomanceable() {}

  std::unique_ptr<TalkRequest> talkedToBy(Player &p) override;
};

} // namespace Pathos

#endif // PATHOS_HERMES
