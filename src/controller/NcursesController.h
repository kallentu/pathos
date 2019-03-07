#ifndef PATHOS_NCURSES_CONTROLLER
#define PATHOS_NCURSES_CONTROLLER

#include "controller/Char.h"
#include "controller/Controller.h"
#include "controller/Input.h"
#include "view/curses/NcursesInstance.h"
#include <memory>

namespace Pathos {

class NcursesController : public Controller {
  NcursesInstance *curses;

public:
  NcursesController(NcursesInstance *curses) : curses{curses} {}

  std::unique_ptr<Input> getInput() override {
    return std::make_unique<Char>(curses->getChar());
  }
};

} // namespace Pathos

#endif // PATHOS_NCURSES_CONTROLLER
