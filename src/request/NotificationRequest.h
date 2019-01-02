#ifndef PATHOS_NOTIFICATION_REQUEST
#define PATHOS_NOTIFICATION_REQUEST

#include <string>
#include <vector>

#include "request/ViewRequest.h"

namespace Pathos {

class View;

struct NotificationRequest : public ViewRequest {
  std::vector<std::string> notifications;

  NotificationRequest(std::vector<std::string> &n);
  void beDrawnBy(View &view) const override;
};

} // namespace Pathos

#endif // PATHOS_NOTIFICATION_REQUEST
