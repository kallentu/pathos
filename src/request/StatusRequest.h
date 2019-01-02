#ifndef PATHOS_STATUS_REQUEST
#define PATHOS_STATUS_REQUEST

#include "request/ViewRequest.h"

namespace Pathos {

class Status;

struct StatusRequest : public ViewRequest {
  Status *status;

  StatusRequest(Status *s);
  void beDrawnBy(View &view) const override;
};

} // namespace Pathos

#endif // PATHOS_STATUS_REQUEST
