#ifndef PATHOS_CHAR
#define PATHOS_CHAR

#include "controller/Input.h"
#include "mode/handler/ModeHandler.h"
#include <memory>
#include <curses.h>

namespace Pathos {

class Event;

class Char : public Input {
  int val;

public:
  enum Arrow {
    Up = KEY_UP,
    Down = KEY_DOWN,
    Left = KEY_LEFT,
    Right = KEY_RIGHT
  };

  enum Ctrl { C = 0x03 };

  enum Special { Space = 0x20 };

  Char(int val) : val{val} {}

  int numValue() const { return val; }
  char charValue() const { return static_cast<char>(val); }
  std::unique_ptr<Event> beHandledBy(ModeHandler *h) {
    return h->handle(*this);
  }
};

} // namespace Pathos

#endif // PATHOS_CHAR
