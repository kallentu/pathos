#ifndef PATHOS_EVENT
#define PATHOS_EVENT

namespace Pathos {

// Events are actions that occur due to user input.
// Depends on different activators and factors of Pathos.
class Event {
public:
  virtual ~Event() {}
};

} // namespace Pathos

#endif // PATHOS_EVENT
