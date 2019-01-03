#ifndef PATHOS_PATHOS_INSTANCE
#define PATHOS_PATHOS_INSTANCE

#include <memory>

#include "abstract/Observable.h"
#include "abstract/Observer.h"
#include "event/Event.h"
#include "request/ViewRequest.h"

namespace Pathos {

class NcursesInstance;
class NcursesView;
class Map;
class Event;

// An instance of the Pathos game.
// Can have multiple instances (game saves)
class PathosInstance : public Observable<ViewRequest>, Observer<Event> {
  std::unique_ptr<NcursesInstance> curses;
  std::unique_ptr<NcursesView> view;
  std::unique_ptr<Map> map;

public:
  PathosInstance();
  ~PathosInstance();

  void process(Event *e) override;
  void run();
};

} // namespace Pathos

#endif // PATHOS_PATHOS_INSTANCE
