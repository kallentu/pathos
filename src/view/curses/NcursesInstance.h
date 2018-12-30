#ifndef PATHOS_NCURSES_INSTANCE
#define PATHOS_NCURSES_INSTANCE

#include <cstddef>
#include <string>

namespace Pathos {

class NcursesInstance {
  size_t height, width;

public:
  NcursesInstance();
  ~NcursesInstance();

  size_t getHeight() { return height; }
  size_t getWidth() { return width; }

  // Input
  int getChar();

  // Printing methods
  void move(size_t y, size_t x);
  void movePrint(size_t y, size_t x, std::string s);
  void addChar(int c);
  void moveAddChar(size_t y, size_t x, int c);
  void print(std::string s);

  // Display methods
  void refresh();

private:
  void updateBounds();
};

} // namespace Pathos

#endif // PATHOS_NCURSES_INSTANCE
