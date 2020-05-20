#include "request/ClearMainStatusRequest.h"
#include "view/View.h"

using namespace Pathos;

void ClearMainStatusRequest::beDrawnBy(View &view) const { view.draw(*this); }
