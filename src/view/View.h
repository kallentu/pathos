#ifndef PATHOS_VIEW
#define PATHOS_VIEW

#include "abstract/Observer.h"
#include "request/ViewRequest.h"

namespace Pathos {

class MapRequest;
class StatusRequest;
class NotificationRequest;
class TalkRequest;

class View : public Observer<ViewRequest> {
public:
  virtual ~View() {}

  void process(ViewRequest *req);

  virtual void draw(const MapRequest &req) = 0;
  virtual void draw(const StatusRequest &req) = 0;
  virtual void draw(const NotificationRequest &req) = 0;
  virtual void draw(const TalkRequest &req) = 0;
};

} // namespace Pathos

#endif // PATHOS_VIEW
