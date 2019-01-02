#ifndef PATHOS_NCURSES_VIEW_DECORATOR
#define PATHOS_NCURSES_VIEW_DECORATOR

#include "view/curses/NcursesView.h"
#include <memory>

namespace Pathos {

class NcursesViewDecorator : public NcursesView {
public:
  NcursesViewDecorator(std::unique_ptr<NcursesView> view)
      : NcursesView{view->getInstance()}, view{std::move(view)} {}

protected:
  std::unique_ptr<NcursesView> view;
};

} // namespace Pathos

#endif // PATHOS_NCURSES_VIEW_DECORATOR
