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

  MultipleRequest() : ViewRequest() {}
  void addRequest(std::unique_ptr<ViewRequest> req) {
    requests.push_back(std::move(req));
  }
  void beDrawnBy(View &view) const override;
};

} // namespace Pathos

#endif // PATHOS_MULTIPLE_REQUEST
