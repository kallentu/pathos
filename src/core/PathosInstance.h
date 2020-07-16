#ifndef PATHOS_PATHOS_INSTANCE
#define PATHOS_PATHOS_INSTANCE

#include <memory>
#include <stack>
#include <vector>

#include "abstract/Observable.h"
#include "abstract/Observer.h"
#include "core/Position.h"
#include "event/Event.h"
#include "request/ViewRequest.h"

namespace Pathos {

  class NcursesInstance;

  class NcursesView;

  class NcursesController;

  class Map;

  class Mode;

  class Event;

  class MapObject;

  class Player;

  class Stats;

  class Status;

  class Quest;

  class QuestManager;

  class CombatManager;

// An instance of the Pathos game.
// Can have multiple instances (game saves)
  class PathosInstance : public Observable<ViewRequest>, Observer<Event> {
    std::unique_ptr<NcursesInstance> curses;
    std::unique_ptr<NcursesView> view;
    std::unique_ptr<NcursesController> controller;
    std::unique_ptr<Map> map;

    // Keep track of actionable position to indicate where the player is facing
    std::unique_ptr<Position> playerPos;
    std::unique_ptr<Position> actionablePos;

    std::unique_ptr<Player> player;

    // Flag to continue or halt game.
    bool continueGame;

    // The modes that the player is currently playing on.
    std::stack<std::unique_ptr<Mode>> modes;

    // Counter for removing in stack of Modes
    int leaveModeRequests;

  public:
    PathosInstance();

    ~PathosInstance() override;

    Player *getPlayer() const;

    NcursesView *getView() const;

    NcursesController *getController() const;

    void setController(std::unique_ptr<NcursesController> contr);

    Position *getPosition() const;

    void setPosition(std::unique_ptr<Position> newPos);

    void setPosition(size_t y, size_t x);

    Position *getActionablePosition() const;

    void setActionablePosition(std::unique_ptr<Position> newPos);

    void setActionablePosition(size_t y, size_t x);

    Map *getMap() const;

    static QuestManager *getQuestManager();

    const Mode *getActiveMode();

    // Available for testing purposes
    bool willContinueGame() const;

    int getLeaveModeRequests() const;

    void runMode(std::unique_ptr<Mode> mode);

    void process(Event *e) override;

    void leaveMode();

    // Stop game entirely and immediately.
    void stop();

  private:
    virtual void run();

    // Generates the information needed for the top status in the view.
    Status generateStatus();
  };

} // namespace Pathos

#endif // PATHOS_PATHOS_INSTANCE
