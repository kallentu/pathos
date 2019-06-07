#include "request/ClearQuickStatusRequest.h"
#include "view/View.h"

using namespace Pathos;

void ClearQuickStatusRequest::beDrawnBy(View &view) const { view.draw(*this); }
