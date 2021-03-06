#ifndef PATHOS_STATUS_VIEW
#define PATHOS_STATUS_VIEW

#include "view/curses/NcursesViewDecorator.h"
#include <memory>

namespace Pathos {

  class NcursesView;

  class MapRequest;

  class StatusRequest;

  class TalkRequest;

  class NotificationRequest;

  class QuestRequest;

  class CombatRequest;

  class ClearQuickStatusRequest;

  class ClearMainStatusRequest;

  class StatusView : public NcursesViewDecorator {

    // Required size of the status column.
    // The amount of characters it takes up
    size_t STATUS_WIDTH = 30;

    // Coordinates for the quick status bar that has
    // NPC interactions.
    size_t QUICK_STATUS_Y, QUICK_STATUS_X;

    size_t height, width;

  public:
    explicit StatusView(std::unique_ptr<NcursesView> view);

    size_t getHeight() const override { return height; }

    size_t getWidth() const override { return width; }

    void setHeight(size_t h) override { height = h; }

    void setWidth(size_t w) override { width = w; }

    // Does not print anything for MapRequest.
    // Transfers drawing to its window.
    void draw(const MapRequest &req) override;

    // Prints StatusRequest information on output.
    void draw(const StatusRequest &req) override;

    // Does not print anything for NotificationRequest.
    // Transfers drawing to its window.
    void draw(const NotificationRequest &req) override;

    // Print TalkRequest underneath the StatusRequest.
    void draw(const TalkRequest &req) override;

    // Prints options at bottom of screen.
    void draw(const QuestRequest &req) override;

    // Prints health, attacks, and other combat related information.
    void draw(const CombatRequest &req) override;

    // Clears the quick status bar.
    void draw(const ClearQuickStatusRequest &req) override;

    // Clears the talk dialogue.
    void draw(const ClearMainStatusRequest &req) override;
  };

} // namespace Pathos

#endif // PATHOS_STATUS_VIEW
