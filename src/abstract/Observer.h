#ifndef PATHOS_OBSERVER
#define PATHOS_OBSERVER

namespace Pathos {

template <typename Event> class Observer {
public:
  virtual ~Observer() {}
  virtual void process(Event *e) = 0;
};

} // namespace Pathos

#endif // PATHOS_OBSERVER
