#ifndef PATHOS_PATHOS_INSTANCE
#define PATHOS_PATHOS_INSTANCE

#include <memory>

#include "abstract/Observable.h"
#include "abstract/Observer.h"
#include "event/Event.h"
#include "request/ViewRequest.h"

namespace Pathos {

class View;
class NcursesInstance;

class PathosInstance : public Observable<ViewRequest>, Observer<Event> {
  std::unique_ptr<NcursesInstance> curses;
  std::unique_ptr<View> view;

public:
  PathosInstance();
  ~PathosInstance();

  void run();
};

} // namespace Pathos

#endif // PATHOS_PATHOS_INSTANCE
