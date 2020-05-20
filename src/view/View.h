#ifndef PATHOS_VIEW
#define PATHOS_VIEW

#include "abstract/Observer.h"
#include "request/ViewRequest.h"

namespace Pathos {

  class MapRequest;

  class StatusRequest;

  class NotificationRequest;

  class TalkRequest;

  class QuestRequest;

  class CombatRequest;

  class ClearQuickStatusRequest;

  class ClearMainStatusRequest;

  class View : public Observer<ViewRequest> {
  public:
    ~View() override = default;

    void process(ViewRequest *req) override;

    virtual void draw(const MapRequest &req) = 0;

    virtual void draw(const StatusRequest &req) = 0;

    virtual void draw(const NotificationRequest &req) = 0;

    virtual void draw(const TalkRequest &req) = 0;

    virtual void draw(const QuestRequest &req) = 0;

    virtual void draw(const CombatRequest &req) = 0;

    virtual void draw(const ClearQuickStatusRequest &req) = 0;

    virtual void draw(const ClearMainStatusRequest &req) = 0;
  };

} // namespace Pathos

#endif // PATHOS_VIEW
