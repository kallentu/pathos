#include "request/ClearEntireStatus.h"
#include "request/ClearQuickStatusRequest.h"
#include "request/ClearMainStatusRequest.h"
#include "request/MultipleRequest.h"
#include "view/View.h"

#include <memory>

using namespace Pathos;

void ClearEntireStatus::beDrawnBy(View &view) const {
  std::unique_ptr<MultipleRequest> request = std::make_unique<MultipleRequest>();
  request->addRequest(std::make_unique<ClearMainStatusRequest>());
  request->addRequest(std::make_unique<ClearQuickStatusRequest>());
  request->beDrawnBy(view);
}