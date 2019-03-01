#ifndef PATHOS_INPUT
#define PATHOS_INPUT

#include <memory>

namespace Pathos {

class Event;
class ModeHandler;

class Input {
public:
  virtual ~Input() {}
  virtual std::unique_ptr<Event> beHandledBy(ModeHandler *h) = 0;
};

} // namespace Pathos

#endif // PATHOS_INPUT
