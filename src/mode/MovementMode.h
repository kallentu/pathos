#ifndef PATHOS_MOVEMENT_MODE
#define PATHOS_MOVEMENT_MODE

#include "mode/Mode.h"
#include "mode/handler/MovementModeHandler.h"
#include <memory>

namespace Pathos {

class PathosInstance;
class ModeHandler;

// Mode where player is moving around the map.
class MovementMode : public Mode {
  std::unique_ptr<MovementModeHandler> handler;

public:
  MovementMode(PathosInstance *inst);

  ModeHandler *getHandler() const override;
};

} // namespace Pathos

#endif // PATHOS_MOVEMENT_MODE
