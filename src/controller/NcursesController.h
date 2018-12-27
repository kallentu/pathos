#ifndef PATHOS_NCURSES_CONTROLLER
#define PATHOS_NCURSES_CONTROLLER

#include "controller/Char.h"
#include "view/curses/NcursesInstance.h"
#include <memory>

namespace Pathos {

class Input;

class NcursesController : public Controller {
  NcursesInstance *curses;

public:
  NcursesController(NcursesInstance *curses) : curses{curses} {}
  ~NcursesController() {}

  std::unique_ptr<Input> getInput() override {
    return std::make_unique<Char>(curses->getChar());
  }
};

} // namespace Pathos

#endif // PATHOS_NCURSES_CONTROLLER
