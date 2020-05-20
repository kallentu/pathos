#ifndef PATHOS_MAP_OBJECT
#define PATHOS_MAP_OBJECT

namespace Pathos {

// A type of object that can be placed in a Map.
class MapObject {
public:
  // Used respectively to represent:
  // Player, Hostile, Friendly, Wall, Ground
  enum class Char { At, Lantern, Sterling, Bound, Empty };

  explicit MapObject(Char c) : c{c} {}
  virtual ~MapObject() = default;

  Char &getCharType() { return c; }

private:
  // Object's symbol in the view.
  Char c;
};

} // namespace Pathos

#endif // PATHOS_MAP_OBJECT
