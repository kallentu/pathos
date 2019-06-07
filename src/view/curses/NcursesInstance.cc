#include "view/curses/NcursesInstance.h"

#include <ncurses.h>
#include <string>

using namespace Pathos;

NcursesInstance::NcursesInstance() {
  initscr();
  keypad(stdscr, TRUE);
  updateBounds();
  raw();
  noecho();
  setCursor(CursorMode::Invisible);
}

NcursesInstance::~NcursesInstance() { endwin(); }

void NcursesInstance::setCursor(CursorMode mode) { curs_set(mode); }

int NcursesInstance::getChar() { return getch(); }

void NcursesInstance::move(size_t y, size_t x) { wmove(stdscr, y, x); }

void NcursesInstance::movePrint(size_t y, size_t x, std::string s) {
  mvprintw(y, x, "%s", s.c_str());
}

void NcursesInstance::addChar(int c) { addch(c); }

void NcursesInstance::moveAddChar(size_t y, size_t x, int c) {
  NcursesInstance::move(y, x);
  addch(c);
}

void NcursesInstance::print(std::string s) { printw("%s", s.c_str()); }

void NcursesInstance::clear() { erase(); }

void NcursesInstance::clearLine() { clrtoeol(); }

void NcursesInstance::clearLine(size_t y, size_t x) {
  move(y, x);
  clearLine();
}

void NcursesInstance::refresh() { refresh(); }

void NcursesInstance::updateBounds() { getmaxyx(stdscr, height, width); }
