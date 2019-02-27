#ifndef PATHOS_CHAR
#define PATHOS_CHAR

#include <memory>

namespace Pathos {

class ModeInputHandler;
class Event;

class Char : public Input {
  int val;

public:
  Char(int val) val{val} {}
  ~Char() {}

  int numValue() const { return val; }
  char charValue() const { return static_cast<char>(val); }
  std::unique_ptr<Event> beHandledBy(ModeInputHandler *h) {
    return h->handle(*this);
  }
};

} // namespace Pathos

#endif // PATHOS_CHAR
