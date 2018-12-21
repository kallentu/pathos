#ifndef PATHOS_OBSERVABLE
#define PATHOS_OBSERVABLE

#include <memory>
#include <unordered_set>

#include "abstract/Observer.h"

namespace Pathos {

template <typename Event> class Observable {
  std::unordered_set<Observer<Event> *> observers;

public:
  virtual ~Observable() {}

  void addObserver(Observer<Event> *o) { observers.insert(o); }
  void removeObserver(Observer<Event> *o) { observers.erase(0); }
  void notify(Event *e) {
    for (auto *o : observers)
      o->process(e);
  }
};

} // namespace Pathos

#endif // PATHOS_OBSERVABLE
