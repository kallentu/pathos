#include "view/curses/NcursesView.h"
#include "view/curses/NcursesInstance.h"

using namespace Pathos;

NcursesView::NcursesView(NcursesInstance *curses)
    : curses{curses}, height{curses->getHeight()}, width{curses->getWidth()} {}
