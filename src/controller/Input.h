#ifndef PATHOS_INPUT
#define PATHOS_INPUT

#include <event/Event.h>
#include <memory>

namespace Pathos {

class ModeHandler;

class Input {
public:
  virtual ~Input() {}
  virtual std::unique_ptr<Event> beHandledBy(ModeHandler *h) = 0;
};

} // namespace Pathos

#endif // PATHOS_INPUT
