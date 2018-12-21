#ifndef PATHOS_VIEW_REQUEST
#define PATHOS_VIEW_REQUEST

namespace Pathos {

class View;

struct ViewRequest {
  virtual ~ViewRequest() {}
  virtual void beDrawnBy(View &view) const = 0;
};

} // namespace Pathos

#endif // PATHOS_VIEW_REQUEST
