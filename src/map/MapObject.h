#ifndef PATHOS_MAP_OBJECT
#define PATHOS_MAP_OBJECT

namespace Pathos {

class MapObject {
public:
  // Used respectively to represent:
  // Player, Hostile, Wall, Ground
  enum class Char { At, Lantern, Bound, Empty };

  MapObject(Char c) : c{c} {}
  virtual ~MapObject() {}

private:
  // Object's symbol in the view.
  Char c;
};

} // namespace Pathos

#endif // PATHOS_MAP_OBJECT
