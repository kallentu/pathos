#ifndef PATHOS_MULTIPLE_REQUEST
#define PATHOS_MULTIPLE_REQUEST

#include "request/ViewRequest.h"
#include <memory>
#include <vector>

namespace Pathos {

class View;

// A group of requests to be processed with the view.
struct MultipleRequest : public ViewRequest {
  std::vector<std::unique_ptr<ViewRequest>> requests;

  MultipleRequest(std::vector<std::unique_ptr<ViewRequest>> &&requests)
      : ViewRequest(), requests{std::move(requests)} {}
  void beDrawnBy(View &view) const override;
};

} // namespace Pathos

#endif // PATHOS_MULTIPLE_REQUEST
