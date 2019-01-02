#include "request/StatusRequest.h"
#include "state/Status.h"
#include "view/View.h"

using namespace Pathos;

StatusRequest::StatusRequest(Status *s) : status{s} {}

void StatusRequest::beDrawnBy(View &view) const { view.draw(*this); }
