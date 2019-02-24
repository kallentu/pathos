#include "request/MultipleRequest.h"
#include "view/View.h"
#include <memory>
#include <vector>

using namespace Pathos;

void MultipleRequest::beDrawnBy(View &view) const {
  // Precondition: Requests must be sent in order.
  for (auto &req : requests) {
    req->beDrawnBy(view);
  }
}
