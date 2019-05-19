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
class NcursesController;
class Map;
class Event;
class MapObject;
class Player;
class Stats;

// An instance of the Pathos game.
// Can have multiple instances (game saves)
class PathosInstance : public Observable<ViewRequest>, Observer<Event> {
  std::unique_ptr<NcursesInstance> curses;
  std::unique_ptr<NcursesView> view;
  std::unique_ptr<NcursesController> controller;
  std::unique_ptr<Map> map;
  std::unique_ptr<Player> player;
  std::unique_ptr<Position> playerPos;
  std::unique_ptr<Stats> stats;

  // Flag to continue or halt game.
  bool continueGame;

public:
  PathosInstance();
  ~PathosInstance();

  Player *getPlayer() const;
  NcursesView *getView() const;
  Position *getPosition() const;
  void setPosition(std::unique_ptr<Position> newPos);
  void setPosition(size_t y, size_t x);
  Map *getMap() const;
  Stats *getStats();

  void process(Event *e) override;
  void run();

  // Stop game entirely and immediately.
  void stop();
};

} // namespace Pathos

#endif // PATHOS_PATHOS_INSTANCE
