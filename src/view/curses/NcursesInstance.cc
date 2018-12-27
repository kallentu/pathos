#include "view/curses/NcursesInstance.h"

#include <ncurses.h>
#include <string>

using namespace Pathos;

NcursesInstance::NcursesInstance() {
  initscr();
  updateBounds();
  raw();
}

NcursesInstance::~NcursesInstance() { endwin(); }

int NcursesInstance::getChar() { return getch(); }

void NcursesInstance::move(size_t y, size_t x) { wmove(stdscr, y, x); }

void NcursesInstance::movePrint(size_t y, size_t x, std::string s) {
  mvprintw(y, x, "%s", s.c_str());
}

void NcursesInstance::print(std::string s) { printw("%s", s.c_str()); }

void NcursesInstance::refresh() { refresh(); }

void NcursesInstance::updateBounds() { getmaxyx(stdscr, height, width); }
