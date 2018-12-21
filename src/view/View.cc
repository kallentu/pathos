#include "view/View.h"

using namespace Pathos;

void View::process(ViewRequest *req) { req->beDrawnBy(*this); }
