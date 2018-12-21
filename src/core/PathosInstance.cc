#include "core/PathosInstance.h"
#include "abstract/Observable.h"
#include "request/ViewRequest.h"
#include "view/curses/MapView.h"
#include "view/curses/NcursesInstance.h"

using namespace Pathos;

PathosInstance::PathosInstance()
    : curses{std::make_unique<NcursesInstance>()},
      view{std::make_unique<MapView>(curses.get())} {
  Observable<ViewRequest>::addObserver(view.get());
}

PathosInstance::~PathosInstance() {}

void PathosInstance::run() {}
