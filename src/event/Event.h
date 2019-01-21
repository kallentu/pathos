#ifndef PATHOS_EVENT
#define PATHOS_EVENT

namespace Pathos {

class PathosInstance;

// Events are actions that occur due to user input.
// Depends on different activators and factors of Pathos.
class Event {
public:
  virtual ~Event() {}

  // Induces the event, triggering events that need to occur.
  virtual void begin(PathosInstance *inst) = 0;
};

} // namespace Pathos

#endif // PATHOS_EVENT
