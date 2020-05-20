#ifndef PATHOS_CLEAR_ENTIRE_STATUS
#define PATHOS_CLEAR_ENTIRE_STATUS

#include "request/ViewRequest.h"

namespace Pathos {

  class View;

  // A request for clearing both the main and quick status views.
  struct ClearEntireStatus : public ViewRequest {
  public:
    void beDrawnBy(View &view) const override;
  };

} // namespace Pathos

#endif // PATHOS_CLEAR_ENTIRE_STATUS
