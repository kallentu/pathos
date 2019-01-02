#ifndef PATHOS_NCURSES_VIEW
#define PATHOS_NCURSES_VIEW

#include <memory>

#include "view/View.h"

namespace Pathos {

class NcursesInstance;

class NcursesView : public View {
  NcursesInstance *curses;
  size_t height, width;

public:
  NcursesView(NcursesInstance *c);

  NcursesInstance *getInstance() const { return curses; }
  virtual size_t getHeight() const { return height; }
  virtual size_t getWidth() const { return width; }

  virtual void setHeight(size_t newHeight) { height = newHeight; }
  virtual void setWidth(size_t newWidth) { width = newWidth; }
};

} // namespace Pathos

#endif // PATHOS_NCURSES_VIEW
