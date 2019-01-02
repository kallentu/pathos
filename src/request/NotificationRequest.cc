#include "request/NotificationRequest.h"
#include "view/View.h"
#include <string>
#include <vector>

using namespace Pathos;

// TODO

NotificationRequest::NotificationRequest(std::vector<std::string> &n)
    : notifications{n} {}

void NotificationRequest::beDrawnBy(View &view) const { view.draw(*this); }
