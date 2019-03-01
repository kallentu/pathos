#include "mode/MovementMode.h"
#include "core/PathosInstance.h"
#include "mode/handler/MovementModeHandler.h"
#include <memory>

using namespace Pathos;

MovementMode::MovementMode(PathosInstance *inst)
    : Mode(inst), handler{std::make_unique<MovementModeHandler>()} {}

ModeHandler *MovementMode::getHandler() const { return handler.get(); }
