#ifndef PATHOS_POSITION
#define PATHOS_POSITION

#include <cstddef>

namespace Pathos {

// Simple structure for position.
struct Position {
  size_t y;
  size_t x;

  Position(size_t y, size_t x) : y{y}, x{x} {}
};

} // namespace Pathos

#endif // PATHOS_POSITION
