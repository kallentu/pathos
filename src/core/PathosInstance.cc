#include "core/PathosInstance.h"
#include "abstract/Observable.h"
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
      player{std::make_unique<Player>()}, activeMapObject{nullptr} {
  Observable<ViewRequest>::addObserver(view.get());
}

PathosInstance::~PathosInstance() {}

void PathosInstance::process(Event *e) {}

void PathosInstance::run() {
  MapRequest mreq = MapRequest(map.get());
  Observable<ViewRequest>::notify(&mreq);

  // TODO: Remove getChar below. Replace with controller.
  // Only there for testing purposes.
  curses->getChar();

  std::unique_ptr<Status> status = std::make_unique<Status>(Status{20, 10});
  StatusRequest sreq = StatusRequest(status.get());
  Observable<ViewRequest>::notify(&sreq);

  curses->getChar();
}
