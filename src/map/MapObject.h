#ifndef PATHOS_MAP_OBJECT
#define PATHOS_MAP_OBJECT

namespace Pathos {

class MapObject {
public:
  enum class Char { Lantern };

  MapObject(Char c) : c{c} {}
  virtual ~MapObject() {}

private:
  // Object's symbol in the view.
  Char c;
};

} // namespace Pathos

#endif // PATHOS_MAP_OBJECT
