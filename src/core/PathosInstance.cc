#include "core/PathosInstance.h"
#include "abstract/Observable.h"
#include "core/Position.h"
#include "map/Map.h"
#include "mob/player/Player.h"
#include "request/MapRequest.h"
#include "request/StatusRequest.h"
#include "request/ViewRequest.h"
#include "state/Status.h"
#include "view/curses/MapView.h"
#include "view/curses/NcursesInstance.h"
#include "view/curses/StatusView.h"

using namespace Pathos;

PathosInstance::PathosInstance()
    : curses{std::make_unique<NcursesInstance>()},
      view{std::make_unique<StatusView>(
          std::make_unique<MapView>(curses.get()))},
      map{std::make_unique<Map>(curses->getHeight(), curses->getWidth())},
      player{std::make_unique<Player>()}, 
      playerPos{std::make_unique<Position>(1, 1)} {
  Observable<ViewRequest>::addObserver(view.get());
}

PathosInstance::~PathosInstance() {}

Player *PathosInstance::getPlayer() const { return player.get(); }

NcursesView *PathosInstance::getView() const { return view.get(); }

Position *PathosInstance::getPosition() const { return playerPos.get(); }

void PathosInstance::setPosition(std::unique_ptr<Position> newPos) {
  playerPos = std::move(newPos);
}

void PathosInstance::setPosition(size_t y, size_t x) {
  playerPos = std::make_unique<Position>(y, x);
}

Map *PathosInstance::getMap() const { return map.get(); }

void PathosInstance::process(Event *e) {}

void PathosInstance::run() {
  MapRequest mreq = MapRequest(map.get(), getPosition());
  Observable<ViewRequest>::notify(&mreq);

  // TODO: Remove getChar below. Replace with controller.
  // Only there for testing purposes.
  curses->getChar();

  std::unique_ptr<Status> status = std::make_unique<Status>(Status{20, 10});
  StatusRequest sreq = StatusRequest(status.get());
  Observable<ViewRequest>::notify(&sreq);

  curses->getChar();
}
