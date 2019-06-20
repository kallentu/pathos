#include "request/ClearTalkRequest.h"
#include "view/View.h"

using namespace Pathos;

void ClearTalkRequest::beDrawnBy(View &view) const { view.draw(*this); }
