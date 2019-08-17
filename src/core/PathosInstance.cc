#include "core/PathosInstance.h"
#include "abstract/Observable.h"
#include "controller/NcursesController.h"
#include "core/Position.h"
#include "event/Event.h"
#include "map/AthensMap.h"
#include "mob/player/Player.h"
#include "mode/Mode.h"
#include "mode/handler/ModeHandler.h"
#include "quest/Quest.h"
#include "quest/QuestManager.h"
#include "request/MapRequest.h"
#include "request/StatusRequest.h"
#include "request/ViewRequest.h"
#include "state/Stats.h"
#include "state/Status.h"
#include "view/curses/MapView.h"
#include "view/curses/NcursesInstance.h"
#include "view/curses/StatusView.h"

using namespace Pathos;

PathosInstance::PathosInstance()
    : curses{std::make_unique<NcursesInstance>()},
      view{std::make_unique<StatusView>(
          std::make_unique<MapView>(curses.get()))},
      controller{std::make_unique<NcursesController>(curses.get())},
      map{std::make_unique<AthensMap>()}, player{std::make_unique<Player>()},
      playerPos{std::make_unique<Position>(1, 1)},
      actionablePos{std::make_unique<Position>(2, 1)},
      stats{std::make_unique<Stats>()},
      questManager{std::make_unique<QuestManager>()}, continueGame{true},
      leaveModeRequests{0} {
  addObserver(view.get());
}

PathosInstance::~PathosInstance() {}

Player *PathosInstance::getPlayer() const { return player.get(); }

NcursesView *PathosInstance::getView() const { return view.get(); }

NcursesController *PathosInstance::getController() const {
  return controller.get();
}

void PathosInstance::setController(std::unique_ptr<NcursesController> contr) {
  controller = std::move(contr);
}

Position *PathosInstance::getPosition() const { return playerPos.get(); }

void PathosInstance::setPosition(std::unique_ptr<Position> newPos) {
  playerPos = std::move(newPos);
}

void PathosInstance::setPosition(size_t y, size_t x) {
  playerPos = std::make_unique<Position>(y, x);
}

Position *PathosInstance::getActionablePosition() const {
  return actionablePos.get();
}

void PathosInstance::setActionablePosition(std::unique_ptr<Position> newPos) {
  actionablePos = std::move(newPos);
}

void PathosInstance::setActionablePosition(size_t y, size_t x) {
  actionablePos = std::make_unique<Position>(y, x);
}

Map *PathosInstance::getMap() const { return map.get(); }

Stats *PathosInstance::getStats() { return stats.get(); }

QuestManager *PathosInstance::getQuestManager() { return questManager.get(); }

const Mode *PathosInstance::getActiveMode() {
  return modes.empty() ? nullptr : modes.top().get();
}

void PathosInstance::process(Event *e) { e->begin(this); }

void PathosInstance::run() {
  std::unique_ptr<Event> event;

  while (!leaveModeRequests && continueGame && !modes.empty()) {
    MapRequest mreq = MapRequest(map.get(), getPosition());
    Observable<ViewRequest>::notify(&mreq);

    event = modes.top().get()->getHandler()->handle(controller->getInput());

    if (event)
      process(event.get());
  }

  // TODO: Remove getChar below. Replace with controller.
  // Only there for testing purposes.
  // curses->getChar();

  // std::unique_ptr<Status> status = std::make_unique<Status>(Status{20, 10});
  // StatusRequest sreq = StatusRequest(status.get());
  // Observable<ViewRequest>::notify(&sreq);

  // curses->getChar();
}

void PathosInstance::runMode(std::unique_ptr<Mode> mode) {
  modes.push(std::move(mode));
  run();
  while (leaveModeRequests > 0) {
    modes.pop();
    --leaveModeRequests;
  }
}

void PathosInstance::stop() { continueGame = false; }

void PathosInstance::leaveMode() { ++leaveModeRequests; }

void PathosInstance::addObserver(NcursesView *view) {
  Observable<ViewRequest>::addObserver(view);
}

bool PathosInstance::willContinueGame() const { return continueGame; }

int PathosInstance::getLeaveModeRequests() const { return leaveModeRequests; }
