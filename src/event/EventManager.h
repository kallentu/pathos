#ifndef PATHOS_EVENT_MANAGER
#define PATHOS_EVENT_MANAGER

#include "event/Event.h"
#include <memory>
#include <vector>

namespace Pathos {

class Player;
class Hostile;
class Friendly;
class Romanceable;
class QuestGiver;
class QuestRecipient;
class Merchant;
class Wall;
class Ground;

// Manages the event of a MapObject that the user is directed towards.
// Holds no events inately, returns the events needed.
class EventManager final {
public:
  EventManager() {}

  std::vector<std::unique_ptr<Event>> getEventList(Player &p);
  std::vector<std::unique_ptr<Event>> getEventList(Hostile &h);
  std::vector<std::unique_ptr<Event>> getEventList(Friendly &f);
  std::vector<std::unique_ptr<Event>> getEventList(Romanceable &r);
  std::vector<std::unique_ptr<Event>> getEventList(QuestGiver &qg);
  std::vector<std::unique_ptr<Event>> getEventList(QuestRecipient &qr);
  std::vector<std::unique_ptr<Event>> getEventList(Merchant &m);
  std::vector<std::unique_ptr<Event>> getEventList(Wall &w);
  std::vector<std::unique_ptr<Event>> getEventList(Ground &g);
};

} // namespace Pathos

#endif // PATHOS_EVENT_MANAGER
