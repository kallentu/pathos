#ifndef PATHOS_CLEAR_QUICK_STATUS_REQUEST
#define PATHOS_CLEAR_QUICK_STATUS_REQUEST

#include "request/ViewRequest.h"

namespace Pathos {

class View;

// A request for clearing the quick status bar on the StatusView.
struct ClearQuickStatusRequest : public ViewRequest {
public:
  void beDrawnBy(View &view) const override;
};

} // namespace Pathos

#endif // PATHOS_CLEAR_QUICK_STATUS_REQUEST
