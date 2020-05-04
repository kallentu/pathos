#ifndef PATHOS_MAP_VIEW
#define PATHOS_MAP_VIEW

#include "core/Position.h"
#include "map/Map.h"
#include "view/curses/NcursesView.h"
#include <memory>

namespace Pathos {

  class MapRequest;

  class StatusRequest;

  class NotificationRequest;

  class TalkRequest;

  class NcursesInstance;

  class QuestRequest;

  class ClearQuickStatusRequest;

  class ClearTalkRequest;

  class MapView : public NcursesView {
    // TODO: Make the MapManager own the map instead of the MapView
    size_t height, width;
    Map *map;

    // Location on the map that the player is located.
    Position *playerPos;

  public:
    explicit MapView(NcursesInstance *curses);

    Map *getMap() const { return map; }

    Position *getPlayerPosition() const { return playerPos; }

    size_t getHeight() const override { return height; }

    size_t getWidth() const override { return width; }

    void setHeight(size_t h) override { height = h; }

    void setWidth(size_t w) override { width = w; }

    // Prints the Map from the MapRequest using ncurses.
    void draw(const MapRequest &req) override;

    // Does not print anything for StatusRequest.
    void draw(const StatusRequest &req) override;

    // Does not print anything for NotificationRequest.
    void draw(const NotificationRequest &req) override;

    // Does not print anything for TalkRequest.
    void draw(const TalkRequest &req) override;

    // Does not print anything for QuestRequest.
    void draw(const QuestRequest &req) override;

    // Updates map based on state of combat.
    void draw(const CombatRequest &req) override;

    // Does not print anything for ClearQuickStatusRequest.
    void draw(const ClearQuickStatusRequest &req) override;

    // Does not print anything for ClearTalkRequest.
    void draw(const ClearTalkRequest &req) override;

  private:
    void drawMap();

    // Draws Player and used only after drawMap()
    void drawPlayer();

    void drawPlayer(size_t mapYStart, size_t mapXStart);

    // Map starting positions for printing. Scrolling in effect.
    size_t getMapYStart() const;

    size_t getMapXStart() const;
  };

} // namespace Pathos

#endif // PATHOS_MAP_VIEW
