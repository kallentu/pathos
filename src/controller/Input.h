#ifndef PATHOS_INPUT
#define PATHOS_INPUT

#include <memory>

namespace Pathos {

class Event;
class InputHandler;

class Input {
public:
  virtual ~Input() {}
  virtual std::unique_ptr<Event> beHandledBy(InputHandler *h) = 0;
};

} // namespace Pathos

#endif // PATHOS_INPUT
