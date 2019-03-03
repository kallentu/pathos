#ifndef PATHOS_PATHOS_INSTANCE
#define PATHOS_PATHOS_INSTANCE

#include <memory>

#include "abstract/Observable.h"
#include "abstract/Observer.h"
#include "core/Position.h"
#include "event/Event.h"
#include "request/ViewRequest.h"

namespace Pathos {

class NcursesInstance;
class NcursesView;
class Map;
class Event;
class MapObject;
class Player;

// An instance of the Pathos game.
// Can have multiple instances (game saves)
class PathosInstance : public Observable<ViewRequest>, Observer<Event> {
  std::unique_ptr<NcursesInstance> curses;
  std::unique_ptr<NcursesView> view;
  std::unique_ptr<Map> map;
  std::unique_ptr<Player> player;
  std::unique_ptr<Position> playerPos;

public:
  PathosInstance();
  ~PathosInstance();

  Player *getPlayer() const;
  NcursesView *getView() const;
  Position *getPosition() const;
  void setPosition(std::unique_ptr<Position> newPos);
  void setPosition(size_t y, size_t x);
  Map *getMap() const;

  void process(Event *e) override;
  void run();
};

} // namespace Pathos

#endif // PATHOS_PATHOS_INSTANCE
